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
int n;
int MAIN(){
    int a,b,c;cin>>a>>b>>c;
    if(c/2>=b)return cout<<3*b<<endl,0;
    int ans=(c/2)*2+c/2;
    b-=c/2;
    if(a<=b/2)cout<<ans+a*3<<endl;
    else cout<<ans+(b/2)*2+b/2<<endl;

    return 0;
}
int32_t main(){
    IOS;
    int t=1;
    cin>>t;
    while(t--)MAIN();
    return 0;
}