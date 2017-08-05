#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>

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
            std::map<std::string, int> word_count = std::map<std::string, int>();
            int line_number = 1;
            while (std::getline(to_read, line)) {
                if (number_line_flag) {
                    std::cout << std::setw(4) << line_number++ << " ";
                }
                if (word_count_flag) {
                    std::stringstream ss(line);
                    std::string word;
                    while (ss >> word) {
                        if (word_count.find(word) == word_count.end()) {
                            word_count[word] = 1;
                        } else {
                            word_count[word]++;
                        }
                    }
                }
                std::cout << line << std::endl;
            }
            to_read.close();
            if (word_count_flag) {
                std::cout << std::endl << "Word Count: " << std::endl;
                for (auto& wc : word_count) {
                    std::cout << wc.first << ": " << wc.second << std::endl;
                }
                std::cout << std::endl;
            }
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
        for (int i = 1; i < argc; i++) {
            if (argv[i][0] == '-') { /* Detect flags */
                if (sizeof(argv[i]) > 1) {
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
        }
        output_files(start_index, argc - 1, argv);
    }
}
