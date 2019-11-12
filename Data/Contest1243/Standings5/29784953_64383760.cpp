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
#define pii pair<int, int>
int k,n,f[maxn];
string s,t;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Task".inp", "r", stdin);
//    freopen(Task".out", "w", stdout);
   cin >> k;
   while(k--)
   {
       cin >> n;
       cin >> s;
       cin >> t;
       int dem=0;
       for(int i=0; i<n; ++i)
       {
           if(s[i]!=t[i])
           {
               ++dem;
               f[dem]=i;
           }
       }
       if(dem==1 || dem > 2) cout<<"NO\n";
       else if(dem==2)
       {
           if(s[f[1]]==s[f[2]] && t[f[2]]==t[f[1]])
             cout<<"YES\n";
           else cout<<"NO\n";
       }
       else cout<<"YES\n";
   }
}
