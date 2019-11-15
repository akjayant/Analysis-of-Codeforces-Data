//    KHAz
#include <bits/stdc++.h>
#define maxn 200005
#define Task ""
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define pii pair< int , int >
#define reset(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
int t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 //   freopen(Task".inp","r",stdin);
  //  freopen(Task".out","w",stdout);
  cin>>t;
    while(t--)
    {
        int a ,b;cin>>a>>b;
        if(__gcd(a,b)>1) cout << "Infinite";
        else cout << "Finite";
        cout << '\n';
    }
    return 0;
}
