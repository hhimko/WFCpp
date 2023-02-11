#include <iostream>

#include "./utils.hpp"


int main() {
    uint32_t pix_w, pix_h;
    std::uint32_t* pixels = WFCpp::Utils::loadPPM("./samples/test.ppm", &pix_w, &pix_h);

    for (size_t i=0; i < pix_h * pix_w; ++i){
        std::cout << pixels[i] << std::endl;
    }
    
    return 0;
}
