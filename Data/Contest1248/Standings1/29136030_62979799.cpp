#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n);
    reverse(ar,ar+n);
    ll ans=0;
    ll h=n/2;
    if(n%2)h++;
    for(int i=0;i<h;i++){
        ans+=ar[i];
    }
    ans*=ans;
    ll sum=0;
    for(int i=h;i<n;i++)
        sum+=ar[i];
    sum*=sum;
    ans+=sum;
    cout<<ans;
}
