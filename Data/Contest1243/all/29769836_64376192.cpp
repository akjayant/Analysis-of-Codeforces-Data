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
const int maxn = 1e5 + 10;
int cnt[maxn];
int main(){
    int T;
    cin >> T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        int n;
        read(n);
        for(int i=1; i<=n; i++){
            int tmp;
            read(tmp);
            cnt[tmp]++;
        }
        for(int i=n; i>=1; i--){
            cnt[i] += cnt[i+1];
        }
        for(int i=n; i>=1; i--){
            if (cnt[i] >= i){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}