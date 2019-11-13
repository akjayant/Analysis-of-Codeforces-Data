#include <bits/stdc++.h>
#define ll long long
//#define int long long
#define D double
#define F first
#define S second
#define sc scanf
#define pr printf
#define B break
#define R return
#define C continue
#define pb push_back
#define double long double
//#define sz size()
#define P pair <ll,ll>
#define pi acos(-1)
using namespace std;
ll mod=1e9+7;;
ll inf=1e18+1;
ll n,m;
ll w[200003];
int main() {
    //freopen("dull.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >>t;
    while (t--){
        ll a,b;
        cin >>a>>b;
        if (b<a) swap(a,b);
        ll d=__gcd(a,b);
        //if (a==b) d=1;
        if (d==1){
            cout <<"Finite"<<endl;
        }
        else cout <<"Infinite"<<endl;
    }
    return 0;
}
