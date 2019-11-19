#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
LL Gcd(LL a,LL b){if (b == 0) return a; return Gcd(b , a%b);}
LL Lcm(LL a, LL b){ return a/Gcd(a,b)*b;}
template <class T>
void read(T &x) {
    static char ch;
    static bool neg;
    for(ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar());
    for(x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar());
    x = neg ? -x : x;
}
const int maxn = 1e6 + 10;
vector<LL> calc(LL n){
    vector<LL> res;
    int tag = 0;
    for(LL i=2; i*i <= n; i++){
        if (n % i == 0){
            while(n % i == 0) n/=i;
            res.push_back(i);
        }
    }
    if (n > 1) res.push_back(n);
    return res;
}
int main(){
    LL n;
    cin >> n;
    vector<LL> p = calc(n); 
    if (p.size() == 1){
        cout << p[0] << endl;
    }else{
        cout << 1 << endl;
    }
    return 0;
}   