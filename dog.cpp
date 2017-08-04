#include <iostream>
#include <string>
#include <fstream>

void mirror_input() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << input << std::endl;
    }
}

void output_files(int num_files, char** file_names) {
    
    for (int i = 1; i <= num_files; i++) {
        std::ifstream to_read(file_names[i]);
        std::string line;

        if (to_read.is_open()) {
            while (std::getline(to_read, line)) {
                std::cout << line << std::endl;
            }
            to_read.close();
        } else {
            std::cout << "dog: " << file_names[i] << ": No such file or directory" << std::endl;
        }
    }
}

int main (int argc, char** argv) {
    if (argc == 1) {
        mirror_input();
    } else {
        output_files(argc - 1, argv);
    }
}
