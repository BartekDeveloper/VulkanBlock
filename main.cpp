
#include "src/test_1/first_test.hpp"

//* std
#include <iostream>
#include <cstdlib>
#include <exception>

int main() {
    
    BlockyVulkan::FirstTest app{};

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}