#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const long long MOD = 1e9 + 7;

int A[MAXN];
long long F[MAXN];
char S[MAXN];
int main(){
    F[0] = 1, F[1] = 1;   F[2] = 2;
    for(int i = 3 ; i < MAXN ; i++) F[i] = F[i - 1] + F[i - 2], F[i] %= MOD;

    int t = 0, cnt = 0;
    scanf("%s", S);

    long long ans = 1;

    int N = strlen(S);
    for(int i = 0; i < N ; i++){
        if(S[i] == 'u' || S[i] == 'w'){
            if(S[i] == 'u') {
                if(t == 1) cnt++;
                else ans = ans * F[cnt] % MOD, cnt = 1, t = 1;
            }
            else {
                return 0 * printf("0");
            }
        }

        else if(S[i] == 'm' || S[i] == 'n'){
            if(S[i] == 'n') {
                if(t == 2) cnt++;
                else ans = ans * F[cnt] % MOD, cnt = 1, t = 2;
            }
            else {
                return 0 * printf("0");
            }
        }
        else ans = ans * F[cnt] % MOD, cnt = 0, t = 0;
    }

    ans = ans * F[cnt] % MOD;
    printf("%lld", ans);
    return 0;
}