#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll sum = 0;
    ll i;
    for(i=0; i<n; i++)
    {
        sum+=(s[i]-'0');
    }
    if (sum == 0) // нет лестниц
    {
        cout<<n<<endl;
        return;
    }
    ll cnt1 = 0, cnt2 = 0;
    for(i=0; i<n; i++)
    {
        if (s[i]=='1') cnt1 = max(cnt1, i+1);
    }
    for(i = n - 1; i>=0; i--)
    {
        if (s[i]=='1') cnt2 = max(cnt2, n-i);
    }

    cout<< max(max( cnt1*2, cnt2*2), n )<<endl;
    return;




}

int main()
{
/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while (t--)
        solve();

    return 0;
}
