#include <iostream>

#include "./utils.hpp"


int main() {
    uint64_t pix_w, pix_h;
    std::uint8_t* pixels = WFCpp::Utils::loadPPM("./samples/test.ppm", &pix_w, &pix_h);

    for (size_t i=0; i < pix_h * pix_w * 3; ++i){
        std::cout << (int)pixels[i] << std::endl;
    }
    
    return 0;
}
