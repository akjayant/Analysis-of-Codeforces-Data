#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string s1,s2;
vector<ll> vec;
int main()
{
    ll t,n,i,j,k,l;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n;
        cin>>s1>>s2;
        for (i=0;i<n;i++)
            if (s1[i]!=s2[i])
                vec.pb(i);
        ll sz=vec.size();
        if (sz>2)
            cout<<"No\n";
        else
        {
            if (sz==0)
                cout<<"Yes\n";
            else
            {
                char ch=s1[vec[0]];
                s1[vec[0]]=s2[vec[1]];
                s2[vec[1]]=ch;
                if (s1!=s2)
                    cout<<"No\n";
                else
                    cout<<"Yes\n";
            }
        }
        vec.clear();
    }
    return 0;
}