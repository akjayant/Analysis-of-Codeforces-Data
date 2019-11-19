///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task ""
#define maxn 100005
#define MOD 1000000007
#define int long long
#define pii pair<int, int>
long long n;
long long kq;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
   cin >> n;
   kq=n;
   for(int i=2; i<=sqrt(n); ++i)
        if(n%i==0)
   {
       kq=__gcd(kq,i);
       kq=__gcd(kq,n/i);
   }
   cout<<kq;
}
