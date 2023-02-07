#include "./utils.hpp"

#include <fstream>
#include <iostream>
#include <string>


std::string ppmReadToken(std::istream& stream) {
    std::string token;
    stream >> token;

    // ignore comments
    size_t cpos = token.find('#');
    if (cpos != std::string::npos){
        std::string _;
        std::getline(stream, _); // skip rest of line

        return cpos == 0 ? ppmReadToken(stream) : token.substr(0, cpos);
    }

    return token;
}

inline bool parseull(std::string s, uint64_t* var) {
    try { *var = std::stoull(s); }
    catch(const std::invalid_argument& _) { return false; }
    return true;
}

std::uint8_t* WFCpp::Utils::loadPPM(const char* path, std::uint64_t* pixels_width, std::uint64_t* pixels_height) {
    std::fstream f(path);
    if (!f.is_open()) {
        std::cerr << "loadPPM: Failed to open file `" << path << '`' << std::endl;
        return nullptr;
    }

    // header data
    std::string magic, token;
    uint64_t pix_w, pix_h, maxval;
    size_t pix_size;
    uint8_t* pixels;

    magic = ppmReadToken(f);
    if (magic != "P3") {
        std::cerr << "loadPPM: Unknown or unhandled ppm magic `" << magic << '`' << std::endl;
        goto loadPPM_fail_header;
    }

    token = ppmReadToken(f);
    if (!parseull(token, &pix_w) || pix_w == 0) {
        std::cerr << "loadPPM: Invalid image width `" << token << '`' << std::endl;
        goto loadPPM_fail_header;
    }
    *pixels_width = pix_w;

    token = ppmReadToken(f);
    if (!parseull(token, &pix_h) || pix_h == 0) {
        std::cerr << "loadPPM: Invalid image height `" << token << '`' << std::endl;
        goto loadPPM_fail_header;
    }
    *pixels_height = pix_h;

    token = ppmReadToken(f);
    if (!parseull(token, &maxval) || maxval == 0) {
        std::cerr << "loadPPM: Invalid max color value `" << token << '`' << std::endl;
        goto loadPPM_fail_header;
    } else if (maxval > 255) {
        std::cerr << "loadPPM: Max color value greater than 255 is not handled" << std::endl;
        goto loadPPM_fail_header;
    }

    // raster data
    pix_size = pix_w * pix_h * 3;
    pixels = new uint8_t[pix_size];

    uint64_t val;
    for (size_t i=0; i < pix_size; ++i) {
        token = ppmReadToken(f);
        if (token.length() == 0 || !parseull(token, &val)) {
            std::cerr << "loadPPM: File `" << path << "` is corrupted" << std::endl;
            goto loadPPM_fail_raster;
        } else if (val > maxval) {
            std::cerr << "loadPPM: Encountered color value greater than max value `" << val << " > " << maxval << '`' << std::endl;
            goto loadPPM_fail_raster;
        }

        pixels[i] = static_cast<uint8_t>(static_cast<double>(val)/maxval * 255);
    }

    f.close();
    return pixels;

loadPPM_fail_raster:
    delete[] pixels;
loadPPM_fail_header:
    f.close();
    return nullptr;
}

bool WFCpp::Utils::savePPM(std::uint8_t* pixels, std::uint64_t pixels_width, std::uint64_t pixels_height, const char* path) {
    // TODO: unimplemented
    return false;
}
