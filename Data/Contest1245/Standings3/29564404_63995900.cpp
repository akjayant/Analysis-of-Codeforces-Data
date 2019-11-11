#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1LL;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
void _div(int &a,int b){
	a = (a * exp(b,M-2,M)) % M;
}
void _mul(int &a,int b){
	a =  a * b % M;
}
void _sum(int &a,int b){
	a += b;
	if(a >= M) a-=M;
	if(a < 0) a += M;
}
main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(gcd(a,b)==1){
            cout << "Finite" << endl;
        }
        else cout << "Infinite" << endl;
    }
}