#pragma once

#include <cstdint>


namespace WFCpp
{
    namespace Utils
    {
        /*
         * Loads in an array of pixels, padded to RGBA format, from a PPM file. 
         * The alpha component gets automatically set to 0xFF.
         */
        std::uint32_t* loadPPM(const char* path, uint32_t* pixels_width, uint32_t* pixels_height);
        bool savePPM(std::uint32_t* pixels, uint32_t pixels_width, uint32_t pixels_height, const char* path);
    } // namespace Utils
    
} // namespace WFCpp
