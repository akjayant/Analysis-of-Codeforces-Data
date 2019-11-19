#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define SZ(X) X.size()
#define pii pair<int,int>
#define ALL(X) X.begin(),X.end()

using namespace std;

LL gcd(LL a, LL b) {return b ? gcd(b, a % b) : a;}
LL lcm(LL a, LL b) {return a / gcd(a, b) * b;}
LL powmod(LL a, LL b, LL MOD) {LL ans = 1; while (b) {if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2;} return ans;}
const int N = 2e5 + 11;
int t;
int a,b,c,d,k;
int main() {
	ios::sync_with_stdio(false);
    for(cin>>t;t;t--){
        cin>>a>>b>>c>>d>>k;
        int l=a/c+(a%c?1:0);
        int r=b/d+(b%d?1:0);
        if(l+r<=k){
            cout<<l<<' '<<r<<endl;
        }else cout<<-1<<endl;
    }
	return 0;
}
