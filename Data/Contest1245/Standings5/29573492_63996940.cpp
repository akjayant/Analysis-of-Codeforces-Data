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

const int MOD = 2e9;
const int sz = 131072;

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int T; cin>>T;
    int a,b;
    while(T--)
    {
        cin>>a>>b;
        cout<<(__gcd(a,b)==1?"Finite\n":"Infinite\n");

    }

    return 0;
}
