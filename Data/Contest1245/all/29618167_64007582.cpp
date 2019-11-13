#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int mem[200006];
int solve(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    int &ret = mem[n];
    if(~ret) return ret;
    return ret = (solve(n-1) + solve(n-2)) % MOD;
}
char s[200005];
int main() {
    memset(mem, -1, sizeof(mem));
    scanf("%s", s);

    long long res = 1;
    for(int i=0; s[i]; i++){
        if(s[i] == 'm' || s[i] == 'w'){
            puts("0");
            return 0;
        }

        int cnt = 0;
        if(s[i] == 'n'){
            for(;s[i]=='n';i++)
                cnt++;
            i--;
        }else if(s[i] =='u'){
            for(;s[i]=='u'; i++)
                cnt++;
            i--;
        }
        res *= solve(cnt);
        res %= MOD;
    }
    printf("%lld\n", res);
    return 0;
}
