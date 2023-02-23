#pragma once

#include <cstdint>


namespace WFCpp
{
    namespace Utils
    {
        /* 
         * @brief
         *  Loads in an array of pixels, padded to RGBA format, from a PPM file. 
         *  The alpha component gets automatically set to 0xFF.
         * 
         * @param path Path to the .ppm file,
         * @param pixels_width Pointer to an uint32_t, to be set with the loaded image width. Can be nullptr,
         * @param pixels_height Pointer to an uint32_t, to be set with the loaded image height. Can be nullptr.
         * 
         * @returns
         *  Pointer to an array of pixels of size pixels_width*pixels_height, or nullptr on fail.
         */
        std::uint32_t* loadPPM(const char* path, uint32_t* pixels_width, uint32_t* pixels_height);
        bool savePPM(std::uint32_t* pixels, uint32_t pixels_width, uint32_t pixels_height, const char* path);
    } // namespace Utils
    
} // namespace WFCpp
