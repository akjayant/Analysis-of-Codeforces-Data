#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i <= (b);i++)
#define FORD(i,a,b) for (int i = (b); i >= (a);i--)
#define all(v) v.begin(),v.end()
#define REV(v) reverse(v.begin(),v.end())
#define INF 1e9
#define int long long
const int N = 1123456;

using namespace std;

inline long long read(){
    char c = getchar();
    long long t = 0, f = 1;
    while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    return t * f;
}
int mod = 1e9+7;
int bin_pow(int a,int n){
    int res = 1;
    while(n > 0){
        if(n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n/=2;
    }
    return res;
}
void solution(){
    int n,m;
    cin >> n >> m;
    cout << bin_pow((bin_pow(2,m) - 1 + mod) % mod,n);
}

int32_t main(){
    int t;
    t = 1;
    while(t--)
        solution();
}
