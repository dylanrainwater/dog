#include <iostream>
#include <string>
#include <fstream>

int number_line_flag = 0; /* Determines whether or not to display line numbers */
int word_count_flag  = 0; /* Determines whether or not to display word count */

void mirror_input() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << input << std::endl;
    }
}

void output_files(int start_index, int num_files, char** file_names) {
    for (int i = start_index; i <= num_files; i++) {
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
        int start_index = 1;
        for (int i = 1; i < argc - 1; i++) {
            if (argv[i][0] == '-' && sizeof(argv[i]) > 1) { /* Detect flags */
                start_index++;
                switch (argv[i][1]) {
                    case 'n':
                        number_line_flag = 1;
                        break;
                    case 'c':
                        word_count_flag = 1;
                        break;
                    default:
                        std::cerr << "Invalid flag: " << argv[i] << std::endl;
                        break;
                }
            } else {
                std::cerr << "Invalid flag: " << argv[i] << std::endl;
                return -1;
            }
        }
        output_files(start_index, argc - 1, argv);
    }
}
