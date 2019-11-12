#include<bits/stdc++.h>
#define int long long
#define M 998244353
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int32_t main(){
ios
int t=1;
cin>>t;
while(t--)
{
    int n;cin>>n;
    vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));int ans=-1;
    for(int i=1;i<=n;i++)
    {
        int num=n-(lower_bound(all(a),i)-a.begin());
        if(num>=i)ans=i;
    }
    cout<<ans<<'\n';
}
}
