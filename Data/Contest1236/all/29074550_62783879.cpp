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

const int MOD = 9901;
const int sz = 262144;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int t; cin>>t;
    while(t--)
    {
        int ans=0;
        int a,b,c; cin>>a>>b>>c;
        c/=2;
        ans += min(b,c);
        b-=min(b,c);
        b/=2;
        ans+=min(a,b);
        cout<<ans*3<<'\n';
    }
    return 0;
}

