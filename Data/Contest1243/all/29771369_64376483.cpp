#include <bits/stdc++.h>
using namespace std;
#define opt ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long int
// I might be a loser, but I have nothing to lose :p
int main()
{
opt;
ll k,n,ans;
cin>>k;
while(k--)
{
    ans=0;
    cin>>n;
    ll a[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    reverse(a,a+n);
    for(int i=0;i<n;i++)
    {
        ans=max(ans,min((ll)i+1,a[i]));
    }
    cout<<ans<<endl;
}
return 0;
}