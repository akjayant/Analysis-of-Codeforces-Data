#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {

    int t, a, b;
    cin >> t;

    for (int q = 0; q < t; q++) {
        cin >> a >> b;
        bool mark = false;
        for (int i = 2; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                mark = true;
                break;
            }
        }
        if (mark)
            cout << "Infinite\n";
        else
            cout << "Finite\n";
    }
    return 0;
}