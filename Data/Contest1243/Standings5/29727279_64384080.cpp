#include<bits/stdc++.h>
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,i,idx=-1;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        for(i=0;i<n;i++)
        {
            if(s1[i] != s2[i])
            {
                idx=i;
                break;
            }
        }
        if(idx == -1)
        {
            cout<<"Yes\n";
            continue;
        }
        ll f=1;
        for(i=idx+1;i<n;i++)
        {
            if(s1[i] != s2[i] && !f)
            {
                f=1;
                break;
            }
            if(s1[i] != s2[i] && (s1[i] != s1[idx] || s2[i] != s2[idx]))
            {
                f=1;
                break;
            }
            if(s1[i] != s2[i] && (s1[i] == s1[idx] && s2[i] == s2[idx]))
                f=0;
        }
        if(!f)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}