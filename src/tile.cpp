#include "./Tile.hpp"



WFCpp::Tile::Tile(std::uint32_t pixels[], size_t size, const std::string conn_top, const std::string conn_right, const std::string conn_bottom, const std::string conn_left) 
    : m_pixels(pixels), m_size(size), m_conn_top(conn_top), m_conn_right(conn_right), m_conn_bottom(conn_bottom), m_conn_left(conn_left) {}


std::uint32_t* WFCpp::Tile::getPixels() {
    return m_pixels;
}

size_t WFCpp::Tile::getSize() {
    return m_size;
}

const std::string WFCpp::Tile::getTopConnectivityString() {
    return m_conn_top;
}

const std::string WFCpp::Tile::getRightConnectivityString() {
    return m_conn_right;
}


const std::string WFCpp::Tile::getBottomConnectivityString() {
    return m_conn_bottom;
}

const std::string WFCpp::Tile::getLeftConnectivityString() {
    return m_conn_left;
}