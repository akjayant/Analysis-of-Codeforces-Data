#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1006;
ll n, m, i, j, k, a, b, ans, v[N], q;
string s, t;
int main()
{
    cin>>q;
    while(q)
    {
        --q;
        cin>>n>>s>>t;
        i=0;
        while(i<n&&s[i]==t[i])
            i++;
        if(i==n)
        {
            cout<<"Yes\n";
            continue;
        }
        int ok=0;
        for(j=i+1;j<n;j++)
            if(t[i]==t[j]&&s[i]==s[j])
        {
            swap(s[i],t[j]);
            ok=1;
        }
        /**if(!ok)
            for(j=i+1;j<n;j++)
            if(s[j]==s[i])
        {
            swap(s[j],t[i]);
            ok=1;
        }*/
        if(s==t)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
