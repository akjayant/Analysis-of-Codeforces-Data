#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define M 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,ans = 0;
    cin>>n;
    ll x[n], y[n], c[n], k[n], s[n], mc[n], d[n], cnt = 0;
    for(i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for(i=0;i<n;i++)
        cin>>c[i];
    for(i=0;i<n;i++)
        cin>>k[i];
    for(i=0;i<n;i++)
    {
        s[i] = -1;
        mc[i] = c[i];
        d[i] = 0;
    }
    set <pair<ll,ll>> st;
    for(i=0;i<n;i++)
        st.insert(mp(c[i],i));
    while(st.size())
    {
        auto ele = *st.begin();
        st.erase(st.begin());
        d[ele.ss] = 1;
        ans += ele.ff;
        for(i=0;i<n;i++)
            if(d[i] == 0 and (abs(x[i]-x[ele.ss])+abs(y[i]-y[ele.ss]))*(k[i]+k[ele.ss]) < mc[i])
            {
                st.erase(mp(mc[i], i));
                mc[i] = (abs(x[i]-x[ele.ss])+abs(y[i]-y[ele.ss]))*(k[i]+k[ele.ss]);
                st.insert(mp(mc[i], i));
                s[i] = ele.ss;
            }
    }
    cout<<ans<<endl;
    for(i=0;i<n;i++)
        if(s[i] == -1)
            cnt++;
    cout<<cnt<<endl;
    for(i=0;i<n;i++)
        if(s[i] == -1)
            cout<<i+1<<" ";
    cout<<endl;
    cout<<n-cnt<<endl;
    for(i=0;i<n;i++)
        if(s[i] != -1)
            cout<<i+1<<" "<<s[i]+1<<endl;
    return 0;
}
