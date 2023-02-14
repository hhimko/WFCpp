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

inline bool parselong(std::string s, long* var) {
    try { *var = std::stol(s); }
    catch(const std::invalid_argument& _) { return false; }
    return true;
}

std::uint32_t* WFCpp::Utils::loadPPM(const char* path, uint32_t* pixels_width, uint32_t* pixels_height) {
    std::fstream f(path);
    if (!f.is_open()) {
        std::cerr << "loadPPM: Failed to open file `" << path << '`' << std::endl;
        return nullptr;
    }

    // header data
    std::string magic, token;
    long pix_w, pix_h, maxval;
    size_t pix_size;
    uint32_t* pixels;

    magic = ppmReadToken(f);
    if (magic != "P3") {
        std::cerr << "loadPPM: Unknown or unhandled PPM magic `" << magic << '`' << std::endl;
        goto loadPPM_fail_header;
    }

    token = ppmReadToken(f);
    if (!parselong(token, &pix_w) || pix_w <= 0) {
        std::cerr << "loadPPM: Invalid image width `" << token << '`' << std::endl;
        goto loadPPM_fail_header;
    }
    *pixels_width = static_cast<uint32_t>(pix_w);

    token = ppmReadToken(f);
    if (!parselong(token, &pix_h) || pix_h <= 0) {
        std::cerr << "loadPPM: Invalid image height `" << token << '`' << std::endl;
        goto loadPPM_fail_header;
    }
    *pixels_height = static_cast<uint32_t>(pix_h);

    token = ppmReadToken(f);
    if (!parselong(token, &maxval) || maxval <= 0) {
        std::cerr << "loadPPM: Invalid max color value `" << token << '`' << std::endl;
        goto loadPPM_fail_header;
    } else if (maxval > 255) {
        std::cerr << "loadPPM: Max color value greater than 255 is not handled" << std::endl;
        goto loadPPM_fail_header;
    }

    // raster data
    pix_size = pix_w * pix_h;
    pixels = new uint32_t[pix_size]{};

    long val;
    uint32_t col;
    for (size_t i=0; i < pix_size; ++i) {
        col = 0x000000FF;

        for (int ch=0; ch < 3; ++ch) {
            token = ppmReadToken(f);
            if (token.length() == 0 || !parselong(token, &val) || val < 0) {
                std::cerr << "loadPPM: File `" << path << "` is corrupted" << std::endl;
                goto loadPPM_fail_raster;
            } 

            if (val > maxval) val = maxval;
            col |= static_cast<uint8_t>((double)val/maxval * 255) << 8*(3 - ch);
        }
        
        pixels[i] = col;
    }

    f.close();
    return pixels;

loadPPM_fail_raster:
    delete[] pixels;
loadPPM_fail_header:
    f.close();
    return nullptr;
}

bool WFCpp::Utils::savePPM(std::uint32_t* pixels, uint32_t pixels_width, uint32_t pixels_height, const char* path) {
    /// TODO: unimplemented
    return false;
}
