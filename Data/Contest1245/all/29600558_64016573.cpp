#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1e5; 
const int mod = 1e9 + 7;

using ll = long long; 

int f[N + 5];

int inc(int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

void init() {
    f[1] = 1; f[0] = 1;
    for (int i = 2; i <= N; i ++)  
        f[i] = inc(f[i - 1], f[i - 2]); 
}

int n; 
char s[N + 5]; 

int main() {

    init();
    int ans = 1; 
    scanf("%s", s + 1);

    n = strlen(s + 1);
    int lst = 1, len; 
    if (s[1] == 'w' || s[1] == 'm') ans = 0;
    for (int i = 2; i <= n; i ++) {
        if (s[i] == 'w' || s[i] == 'm') ans = 0; 
        if (s[i] != s[i - 1]) {
            //lst = i; 
            if (s[i - 1] == 'u' || s[i - 1] == 'n')
                len = i - lst,
                ans = (ll) ans * f[len] % mod; 
            lst = i;
        } 
    }

    if (s[n] == 'u' || s[n] == 'n') 
        ans = (ll) ans * f[n + 1 - lst] % mod; 

    std::cout << ans << std::endl;

    return 0; 
}