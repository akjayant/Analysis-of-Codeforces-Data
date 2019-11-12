#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long q=1;
    cin>>q;
    while(q--)
    {
        ll n; string s,t;
        vector<ll> dif;
        cin>>n;
        cin.ignore();
        getline(cin,s);
        getline(cin,t);
        for(ll i=0;i<n;++i)
        {
            if(s[i]!=t[i]) dif.push_back(i);
        }
        if(dif.size()==0) cout<<"YES"<<endl;
        else if(dif.size()==2)
        {
            if(s[dif[0]]==s[dif[1]]&&t[dif[0]]==t[dif[1]])
            {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
