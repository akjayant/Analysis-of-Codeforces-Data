#include<bits/stdc++.h>
using namespace std;
#define int long long
#define die(x) return cout << x << endl, 0
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)
#define FILE freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define SZ(x) ((int)(x).size())
typedef long double ld;
typedef long long ll;
int gcd(int x,int y){ return (!y ? x : gcd(y, x%y)); }
int to_int(string sconvert){stringstream geek(sconvert);int xconvert = 0; geek >> xconvert; return xconvert;}
const int MAXN=3e5+30,MAX_LOG=40,INF=1e9,MOD=1e9+7;
const double PI = acos(-1);
int mod(int x) { return (x % MOD + MOD) % MOD; }
int power(int x,int y){
    if(y==0)return 1;
    int c=power(x,y/2);
    c=(c*c)%MOD;
    if(y%2)c=(c*x)%MOD;
    return c;
}
int n,m;
int MAIN(){
    cin>>n>>m;
    cout<<power(mod(power(2,m)-1),n);

    return 0;
}
int32_t main(){
    IOS;
    int t=1;
    //cin>>t;
    while(t--)MAIN();
    return 0;
}