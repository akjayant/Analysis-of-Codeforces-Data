//    KHAz
#include <bits/stdc++.h>
#define maxn 100005
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
string s;
int n,f1[maxn],f2[maxn],dem;
long long ans=1,d[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 //   freopen(Task".inp","r",stdin);
  //  freopen(Task".out","w",stdout);
    cin>>s;
    n=s.length();
    s=' '+s;
    d[2]=2, d[1]=1;
    for(int i=3;i<=n;i++)
    {
        d[i]=(d[i-1]+d[i-2])%MOD;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout << 0;
            return 0;
        }
        if(s[i]=='u')
        {
          //  int dem=0;
            while(s[i]=='u')
            {
                dem++;
                i++;
            }
            i--;
            ans=(ans*d[dem])%MOD;
            dem=0;
        }
        else
        {
            if(s[i]=='n')
            {
                dem=0;
                while(s[i]=='n')
                {
                    dem++;
                    i++;
                }
                i--;
                ans=(ans*d[dem])%MOD;
                dem=0;
            }
            else dem=0;
        }
    }
    cout << ans;
    return 0;
}
