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
const int MAXN=3e3+30,MAX_LOG=40,INF=1e9,MOD=1e9+7;
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
vector<int>v[MAXN];
int MAIN(){
    cin>>n;
    int now=1;
    int num=1;
    int flag=0;
    while(num<=n*n){
        v[now].push_back(num);
        if(flag==0)now++;
        else now--;
        if(now==n+1){
            now=n;flag=1;
        }
        if(now==0){
            now=1;flag=0;
        }
        num++;
    }
    for(int i=1;i<=n;i++){
        for(auto u:v[i])cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
int32_t main(){
    IOS;
    int t=1;
    //cin>>t;
    while(t--)MAIN();
    return 0;
}