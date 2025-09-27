//
// argtest
// argtest.cpp
//
// Project Name: arg test for cpp
//
// Create by: Wirakorn Thanabat
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

int main(int argc, char* argv[]){
    std::cout << argc << std::endl;
    for(int i = 0; i < argc; i++){
        std::cout << i << " " << argv[i] << std::endl;
    }

    return 0;
}