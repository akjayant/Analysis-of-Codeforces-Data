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
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll r=n-1,l=0;
    ll d=0,h=0;
    while(l<=r){
        if(l==r){
            d+=arr[l];
            break;
        }
        d+=arr[r];
        h+=arr[l];
        l++;
        r--;
    }
    ll ans=h*h+d*d;
    cout<<ans;
    return 0;
}
