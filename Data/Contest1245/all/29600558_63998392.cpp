#include <iostream>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); 
}

int main() {

    int T; 
    std::cin >> T; 

    while (T --) {
        int a, b; 
        std::cin >> a >> b;
        int c = gcd(a, b); 
        if (c == 1) std::cout << "Finite\n";
        else std::cout << "Infinite\n";
    }

    return 0;
}