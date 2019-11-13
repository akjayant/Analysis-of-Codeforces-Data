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
const int sz = 262144;

vi ans[311];

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n; cin>>n;
    int i,j;
    int a,b;
    int l=1, r=n*n, mid=l+r>>1, f=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n/2;j++) {ans[i].push_back(l++); ans[i].push_back(r--);}
        if (n&1) {ans[i].push_back(mid + f*(i/2)); f*=-1;}
    }

    for(i=1;i<=n;i++)
    {
        for(int x:ans[i]) cout<<x<<' ';
        cout<<'\n';
    }


    return 0;
}

