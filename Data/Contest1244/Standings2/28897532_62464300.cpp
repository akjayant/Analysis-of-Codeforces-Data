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

        int a,b,c,d,k; cin>>a>>b>>c>>d>>k;
        int a1=(a+c-1)/c;
        int a2=(b+d-1)/d;
        if (a1+a2>k) cout<<-1<<'\n';
        else cout<<a1<<' '<<a2<<'\n';

    }
    return 0;
}
