#include<bits/stdc++.h>
 
using namespace std;
 
#define LL long long
#define pb push_back
#define pLL pair<LL,LL>
#define ff first
#define ss second
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define repb(i,a,b) for(LL i=a;i>=b;--i)
#define ld double
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define SLL set<LL>
#define SpLL set<pLL>
#define FIO ios::sync_with_stdio(false)

int t,a,b;

LL gcd(LL a, LL b) {
    if(a > b) return gcd(b, a);
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    FIO;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(gcd(a, b) == 1) cout <<  "Finite" << endl;
        else cout << "Infinite" << endl;
    }

}