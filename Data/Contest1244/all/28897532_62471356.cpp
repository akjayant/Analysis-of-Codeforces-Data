#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #define watch(x) cout << (#x) << " is " << (x) << '\n'
  #define dashline() cout << "=============\n"
#else
  #define watch(x)
  #define dashline()
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MX = 1e9;
const ll MX2 = 3e18;
const double pi = acos(-1);

const int MOD = 1e9+7;
const int SZ = 524288;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int t; cin>>t;
    while(t--)
    {
        int n;
        string str;
        cin>>n>>str;
        int cnt=0;
        int i,l=MX,r=-1;
        for(i=0;i<n;i++)
        {
            if (str[i]=='1')
            {
                cnt++;
                l=min(i,l);
                r=max(i,r);
            }
        }
        int ans=n;

        if (cnt)
        {
            ans=max(ans,l+1+l+1);
            ans=max(ans,n+1);
            ans=max(ans,n-l+n-l);

            ans=max(ans,r+1+r+1);
            ans=max(ans,n+1);
            ans=max(ans,n-r+n-r);

        }
        cout<<ans<<'\n';
    }
    return 0;
}
