#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pll pair<long long,long long>
#define pdd pair<long double,long double>
#define mp make_pair
#define pb push_back
#define pf push_front
priority_queue<pll,vector<pll>,greater<pll> >pq;
priority_queue<ll,vector<ll>,greater<ll> >pq1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t,a,m;
    cin>>n>>m;
    vector<ll>dp1(n+1,0),dp2(m+1,0);
    dp1[0]=2;
    dp1[1]=2;
    dp2[0]=2;
    dp2[1]=2;
    for(int i=2;i<=n;i++){
        dp1[i]=(dp1[i-1]+dp1[i-2])%mod;
    }
    for(int i=2;i<=m;i++){
        dp2[i]=(dp2[i-1]+dp2[i-2])%mod;
    }
    cout<<(dp1[n]+dp2[m]-2)%mod;

    return 0;
}
