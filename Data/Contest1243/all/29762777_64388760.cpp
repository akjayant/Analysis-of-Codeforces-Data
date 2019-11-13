#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e3 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;

string s,t;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,tot = 0,ff = 1;
        cin>>n;
        cin>>s>>t;
        vector<char>ss;
        vector<char>tt;
        ss.clear();
        tt.clear();
        for(int i=0;i<n;i++)
        {
            if(s[i] != t[i])
            {
                tot ++;
                if(tot > 2)
                {
                    ff = 0;
                    break;
                }
                ss.push_back(s[i]);
                tt.push_back(t[i]);
            }
        }
        if(ff == 0)
            printf("NO\n");
        else
        {
            if(ss[0] == ss[1] && tt[0] == tt[1])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
