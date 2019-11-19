#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;
const LL MOD=1e9+7;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t,n;
    cin>>t;
    string s;
    PII x;
    int k,ans;
    while(t--)
    {
        cin>>n;
        cin>>s;
        k=0;
        x={-1,-1};
        for(int i=0;i<n;i++)
        {
            k+=s[i]-'0';

            if(s[i]=='1')
            {
                if(k==1)
                {
                    x.first=i;
                }
                x.second=i;
            }
        }
        ans=n+k;
        if(k>0)
        {
            ans=max(ans,(n-x.first)*2);
            ans=max(ans,2*x.second+2);
        }
        cout<<ans<<'\n';
    }



}
