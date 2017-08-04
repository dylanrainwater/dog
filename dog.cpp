#include <iostream>
#include <string>

void mirror_input() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << input << std::endl;
    }
}

void output_files() {
    std::cout << "Output mode" << std::endl;
}

int main (int argc, char** argv) {
    if (argc == 1) {
        mirror_input();
    } else {
        output_files();
    }
}
