#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int Gcd(int a,int b){if (b == 0) return a; return Gcd(b , a%b);}
int Lcm(int a, int b){ return a/Gcd(a,b)*b;}
template <class T>
void read(T &x) {
    static char ch;
    static bool neg;
    for(ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar());
    for(x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar());
    x = neg ? -x : x;
}
const int maxn = 1e6 + 10;
char s[maxn],t[maxn];
int main(){
    int T;
    read(T);
    while(T--){
        int n;
        read(n);
        scanf("%s%s",s,t);
        int cnt = 0,pos1 = 0,pos2 = 0;
        for(int i=0; i<n; i++){
            if (s[i] != t[i]) {
                cnt++;
                if (cnt == 1) pos1 = i;
                else if (cnt == 2) pos2 = i;
            }
        }
        if (cnt == 2) {
            if (s[pos1] != s[pos2] || t[pos1] != t[pos2]){
                puts("No");
            }else{
                puts("Yes");
            }            
        }else{
            puts("No");
        }
    }   
    return 0;
}