#include <iostream>

#include "../src/utils.hpp"
#include "../src/tile.hpp"


int main() {
    // Load tile images 
    // A - grass-grass connection, B - tree-top-tree-bottom connecton, C - path-path connection  
    uint32_t tile_size;
    std::uint32_t* grass_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/grass.ppm", &tile_size, nullptr);
    auto grass_tile = WFCpp::Tile(grass_pixels, tile_size, "A", "A", "A", "A", WFCPP_TILE_ROT_ALL);

    std::uint32_t* flowers_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/flowers.ppm", &tile_size, nullptr);
    auto flowers_tile = WFCpp::Tile(flowers_pixels, tile_size, "A", "A", "A", "A", WFCPP_TILE_ROT_NONE);

    std::uint32_t* rock_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/rock.ppm", &tile_size, nullptr);
    auto rock_tile = WFCpp::Tile(rock_pixels, tile_size, "A", "A", "A", "A", WFCPP_TILE_ROT_NONE);

    std::uint32_t* tree_bottom_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/tree_bottom.ppm", &tile_size, nullptr);
    auto tree_bottom_tile = WFCpp::Tile(tree_bottom_pixels, tile_size, "B", "A", "A", "A", WFCPP_TILE_ROT_NONE);

    std::uint32_t* tree_top_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/tree_top.ppm", &tile_size, nullptr);
    auto tree_top_tile = WFCpp::Tile(tree_top_pixels, tile_size, "A", "A", "B", "A", WFCPP_TILE_ROT_NONE);

    std::uint32_t* path_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/path.ppm", &tile_size, nullptr);
    auto path_tile = WFCpp::Tile(path_pixels, tile_size, "C", "A", "C", "A", WFCPP_TILE_ROT_R90);

    std::uint32_t* path_corner_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/path_corner.ppm", &tile_size, nullptr);
    auto path_corner_tile = WFCpp::Tile(path_corner_pixels, tile_size, "A", "A", "C", "C", WFCPP_TILE_ROT_ALL);

    std::uint32_t* path_tee_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/path_tee.ppm", &tile_size, nullptr);
    auto path_tee_tile = WFCpp::Tile(path_tee_pixels, tile_size, "C", "C", "C", "A", WFCPP_TILE_ROT_ALL);

    std::uint32_t* path_end_pixels = WFCpp::Utils::loadPPM("./samples/basic_tileset/path_end.ppm", &tile_size, nullptr);
    auto path_end_tile = WFCpp::Tile(path_end_pixels, tile_size, "C", "A", "A", "A", WFCPP_TILE_ROT_ALL);


    // Free all pixel arrays allocated with Utils::loadPPM
    free(grass_pixels);
    free(flowers_pixels);
    free(rock_pixels);
    free(tree_bottom_pixels);
    free(tree_top_pixels);
    free(path_pixels);
    free(path_corner_pixels);
    free(path_tee_pixels);
    free(path_end_pixels);

    return 0;
}
