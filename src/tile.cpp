#include "./Tile.hpp"


WFCpp::Tile::Tile(std::uint32_t pixels[], size_t size, const std::string conn_top, const std::string conn_right, const std::string conn_bottom, const std::string conn_left, uint8_t rotation_flags) 
    : m_pixels(pixels), m_size(size), m_conn_top(conn_top), m_conn_right(conn_right), m_conn_bottom(conn_bottom), m_conn_left(conn_left), m_rotation_flags(rotation_flags) {}


WFCpp::Tile WFCpp::Tile::rotateLeft() const
{
    uint32_t* pixels = new uint32_t[m_size];
    for (size_t y = 0; y < m_size; ++y) {
        for (size_t x = 0; x < m_size; ++x) {
            pixels[y*m_size + x] = m_pixels[x*m_size + (m_size - 1 - y)];
        }
    }

    return WFCpp::Tile(pixels, m_size, m_conn_top, m_conn_right, m_conn_bottom, m_conn_left, m_rotation_flags);
};

WFCpp::Tile WFCpp::Tile::rotateRight() const
{
    uint32_t* pixels = new uint32_t[m_size];
    for (size_t y = 0; y < m_size; ++y) {
        for (size_t x = 0; x < m_size; ++x) {
            pixels[y*m_size + x] = m_pixels[(m_size - 1 - x)*m_size + y];
        }
    }

    return WFCpp::Tile(pixels, m_size, m_conn_top, m_conn_right, m_conn_bottom, m_conn_left, m_rotation_flags);
};

WFCpp::Tile WFCpp::Tile::flipHorizontally() const
{
    uint32_t* pixels = new uint32_t[m_size];
    for (size_t y = 0; y < m_size; ++y) {
        for (size_t x = 0; x < m_size; ++x) {
            pixels[y*m_size + x] = m_pixels[(m_size - 1 - y)*m_size + x];
        }
    }

    return WFCpp::Tile(pixels, m_size, m_conn_top, m_conn_right, m_conn_bottom, m_conn_left, m_rotation_flags);
};

WFCpp::Tile WFCpp::Tile::flipVertically() const
{
    uint32_t* pixels = new uint32_t[m_size];
    for (size_t y = 0; y < m_size; ++y) {
        for (size_t x = 0; x < m_size; ++x) {
            pixels[y*m_size + x] = m_pixels[y*m_size + (m_size - 1 - x)];
        }
    }

    return WFCpp::Tile(pixels, m_size, m_conn_top, m_conn_right, m_conn_bottom, m_conn_left, m_rotation_flags);
};
