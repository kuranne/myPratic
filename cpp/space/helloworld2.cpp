#include <iostream>
#ifdef __x86_64__
    #define ARCH "x86_64"
#else
    #define ARCH "aarch64"
#endif

int main() {
    std::cout << "Hello" << ARCH << std::endl;
    return 0;
}