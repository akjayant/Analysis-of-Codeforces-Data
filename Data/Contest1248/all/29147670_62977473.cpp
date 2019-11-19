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

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int T; cin>>T;
    while(T--)
    {

    int n,m;
    int i,j;
    ll cnt11=0,cnt12=0,cnt21=0,cnt22=0;
    int x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if (x&1) cnt11++;
        else cnt12++;
    }
    cin>>m;
    while(m--)
    {
        cin>>x;
        if(x&1) cnt21++;
        else cnt22++;
    }
    cout<<cnt11*cnt21+cnt12*cnt22<<'\n';

    }
    return 0;
}

