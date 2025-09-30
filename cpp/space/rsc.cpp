#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int rsinit() {
    string command = "cargo init";
    return system(command.c_str());
}

int rsnew(string name) {
    string command = "cargo new " + name;
    return system(command.c_str());
}

int rsgrep(string pattern) {
    // คล้าย grep "pattern" *
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file()) {
            ifstream file(entry.path());
            if (!file) continue;

            string line;
            int lineNumber = 0;
            while (getline(file, line)) {
                lineNumber++;
                if (line.find(pattern) != string::npos) {
                    cout << entry.path().filename().string()
                         << ":" << lineNumber << ": " << line << endl;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return rsinit();
    }

    string arg = argv[1];
    if (arg == "new" && argc >= 3) {
        return rsnew(argv[2]);
    } else if (arg == "fd" && argc >= 3) {
        return rsgrep(argv[2]);
    } else {
        cerr << "Usage:\n"
             << "  rsc              -> cargo init\n"
             << "  rsc new <name>   -> cargo new <name>\n"
             << "  rsc fd <word>    -> search word in current dir\n";
        return 1;
    }
}