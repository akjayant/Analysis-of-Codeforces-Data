#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define watch(x) cout << (#x) << " is: " << (x) << endl
#define vw(v)                        \
    cout << (#v) << " is: " << endl; \
    for (int B : (v))                \
    {                                \
        cout << B << " ";            \
    }                                \
    cout << endl
#define check(x) cout << "here " << (x) << "?" << endl
#define rep(i, a, b) for (long long i = (a); i < (b); i++)
#define per(i, a) for (long long i = (a - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rv(x) (x).rbegin(), (x).rend()
#define pb push_back
long long const MAX = 2147483647, REALMAX = 9223372036854775806;
int main(){
    FAST_IO
    long long n;
        vector<long long> g;
    cin >> n;
    if(n == 1){
        return cout<<1 , 0;
    }
    for(long long i = 2 ; i <= sqrt(n) ; i += 1){
        while(n%i == 0){
            n /= i;
            g.pb(i);
        }
    }
    if(n > 1){
        g.pb(n);
    }
    if(g[0] == g[g.size()-1]){
        cout << g[0];
    }else{
        cout << 1;
    }
}