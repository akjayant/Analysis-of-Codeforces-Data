#include<bits/stdc++.h>
using namespace std;

auto clk=clock();
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define Mod 1000000007
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define all(x) x.begin(),x.end()

ll power(ll x, ll y) 
{ 
    ll res = 1; 
    x = x % Mod;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % Mod; 

        y = y>>1; 
        x = (x*x) % Mod;   
    } 
    return res; 
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    int x=(power(2,m)-1+Mod)%Mod;
    cout<<power(x,n)<<"\n";
    cerr<<"\n"<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<"\n";
    return 0;
}
