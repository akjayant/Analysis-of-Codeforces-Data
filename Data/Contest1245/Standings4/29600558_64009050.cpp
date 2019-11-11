#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 100;

int n; 
int nr, ns, np; 
char sq[N + 5]; 
char as[N + 5];

int main() {

    std::cin.tie();
    std::cout.tie();

    int T; 
    std::cin >> T; 

    while (T --) {
        std::cin >> n >> nr >> np >> ns;
        for (int i = 1; i <= n; i ++) as[i] = '0';
        scanf("%s", sq + 1);
        int cnt = 0; 
        for (int i = 1; i <= n; i ++) {
            if (sq[i] == 'R' && np) np --, as[i] = 'P', cnt ++; 
            else if (sq[i] == 'P' && ns) ns --, as[i] = 'S', cnt ++; 
            else if (sq[i] == 'S' && nr) nr --, as[i] = 'R', cnt ++; 
        }

        if (cnt < (n + 1) / 2) {
            std::cout << "NO\n"; 
            continue ;
        }
        std::cout << "YES\n";
        for (int i = 1; i <= n; i ++) {
            if (as[i] != '0') continue ;
            if (nr) nr --, as[i] = 'R';
            else if (np) np --, as[i] = 'P';
            else if (ns) ns --, as[i] = 'S'; 
        }
        as[n + 1] = 0;

        std::cout << ("%s", as + 1) << std::endl;
    }

    return 0;
}