#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 101010, MOD = 1e9 + 7;

long long fib[MAXN];
char s[MAXN];

int main() {
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < MAXN; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    scanf("%s", s);
    int N = strlen(s);
    s[N] = 'z';
    int c = 0;
    long long answer = 1;
    for (int i = 0; i <= N; ++i) {
        if (i > 0 && s[i] != s[i - 1] && c > 0) {
            answer = (answer * fib[c]) % MOD;
            c = 0;
        }

        if (s[i] == 'u' || s[i] == 'n') c++;

        if (s[i] == 'm' || s[i] == 'w') {
            answer = 0;
            break;
        }
    }

    printf("%lld\n", answer);

    return 0;
}
