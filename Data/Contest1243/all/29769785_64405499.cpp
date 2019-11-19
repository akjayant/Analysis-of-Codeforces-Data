#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i, n, k, j, N, K;

    cin >> n;
    N = n;
    k = j = 0;
    if(n % 2 == 0) {
        k = 1;
        K = 2;
        while(n % 2 == 0) {
            n /= 2;
            j++;
        }
    }

    for(i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            if(k == 0) {
                K = i;
            }
            k++;
            while(n % i == 0) {
                n /= i;
                j++;
            }
        }
    }

    if(n != 1) {
        if(k == 0) {
            K = n;
        }
        k++;
        j++;
    }

    if(k == 1 && j == 1) {
        cout << N << endl;
    } else if(k == 1 && j > 1) {
        cout << K << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}
