#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

const int mod = 1e9 + 7;

char str[N];

int fib[N];

int main() {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    fib[0] = 1;
    for (int i = 1; i <= len; i ++ ) {
        if (str[i] == 'm' || str[i] == 'w') {
            printf("0\n");
            return 0;
        }
    }
    for (int i = 1; i <= len; i ++ ) {
        if (str[i] == str[i - 1] && str[i] == 'u') {
            fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        }
        else if (str[i] == str[i - 1] && str[i] == 'n') {
            fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        }
        else {
            fib[i] = fib[i - 1];
        }
    }
    cout << fib[len] << endl;
    return 0;
}