#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define ppii pair<pii, pii>
using namespace std;
int a, b;
int gcd(int x, int y)
{
    int r;
    while(y){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("sol.inp", "r", stdin);
    //freopen("sol.out", "w", stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>a>>b;
        if(gcd(a, b)==1) cout<<"Finite"<<'\n';
        else cout<<"Infinite"<<'\n';
    }
}
