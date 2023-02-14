#pragma once

#include <cstdint>
#include <string>


namespace WFCpp
{
    class Tile {
        public:
            std::uint32_t* getPixels();
            size_t getSize();
            const std::string getTopConnectivityString();
            const std::string getRightConnectivityString();
            const std::string getBottomConnectivityString();
            const std::string getLeftConnectivityString();

        public:
            Tile() = delete;
            Tile(std::uint32_t pixels[], size_t size, const std::string conn_top, const std::string conn_right, const std::string conn_bottom, const std::string conn_left);

        private:
            std::uint32_t* m_pixels;
            const size_t m_size;
            const std::string m_conn_top, m_conn_right, m_conn_bottom, m_conn_left;

        private:
            
    };
} // namespace WFCpp
