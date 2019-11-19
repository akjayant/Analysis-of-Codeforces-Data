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
    cin>>t;
    while(t--){
        cin>>n;
        ll e1=0,o1=0,e2=0,o2=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a%2)
                o1++;
            else
                e1++;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>a;
            if(a%2)
                o2++;
            else
                e2++;
        }
        ll ans=o2*o1+e2*e1;
        cout<<ans<<"\n";
    }

    return 0;
}
