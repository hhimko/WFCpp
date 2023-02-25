#pragma once

#include <cstdint>
#include <string>

#define WFCPP_TILE_ROT_NONE 0 /// @brief No tile rotation.
#define WFCPP_TILE_ROT_R90  1 /// @brief CW tile rotation by 90deg. Same as WFCPP_TILE_ROT_L270.
#define WFCPP_TILE_ROT_L270 1 /// @brief CCW tile rotation by 270deg. Same as WFCPP_TILE_ROT_R90.
#define WFCPP_TILE_ROT_R180 2 /// @brief CW tile rotation by 180deg. Same as WFCPP_TILE_ROT_L180.
#define WFCPP_TILE_ROT_L180 2 /// @brief CCW tile rotation by 180deg. Same as WFCPP_TILE_ROT_R180.
#define WFCPP_TILE_ROT_R270 4 /// @brief CW tile rotation by 270deg. Same as WFCPP_TILE_ROT_L90.
#define WFCPP_TILE_ROT_L90  4 /// @brief CCW tile rotation by 90deg. Same as WFCPP_TILE_ROT_R270.
#define WFCPP_TILE_ROT_ALL  7 /// @brief Rotate the tile in all directions.


namespace WFCpp
{
    class Tile {
        public:
            std::uint32_t* getPixels() const { return m_pixels; }
            size_t getSize() const { return m_size; }
            const std::string getTopConnectivityString() const { return m_conn_top; }
            const std::string getRightConnectivityString() const { return m_conn_right; }
            const std::string getBottomConnectivityString() const { return m_conn_bottom; }
            const std::string getLeftConnectivityString() const { return m_conn_left; }
            uint8_t getRotationFlags() const { return m_rotation_flags; }

        public:
            Tile() = delete;
            Tile(std::uint32_t pixels[], size_t size, const std::string conn_top, const std::string conn_right, const std::string conn_bottom, const std::string conn_left, uint8_t rotation_flags);

            Tile rotateLeft() const;
            Tile rotateRight() const;
            Tile flipHorizontally() const;
            Tile flipVertically() const;

        private:
            std::uint32_t* m_pixels;
            const size_t m_size;
            const std::string m_conn_top, m_conn_right, m_conn_bottom, m_conn_left;
            uint8_t m_rotation_flags;

    };
} // namespace WFCpp
