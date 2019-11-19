#include<bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef pair<int,int>   pii;
typedef pair<ll,ll>     pll;

#define     all(a)  a.begin(), a.end()
#define     pb      push_back
#define     ff      first
#define     ss      second

#define     inf     (1000000000)
#define     infl    (1000000000000000000LL)
#define     MAX     3000007
#define     MOD     1000000007
#define     eps     1e-6
#define     FIN     freopen("input.txt","r",stdin);
#define     FOUT    freopen("output.txt","w",stdout);
#define     SET(a)  memset((a), -1, sizeof(a))
#define     CLR(a)  memset((a), 0, sizeof(a))
#define     dbg(x)  cout << #x << " = " << x << endl

//pos is 0 based
inline bool checkBit(int mask,int pos){ return  (bool)(mask & (1<<pos));}
inline int setBit(int mask,int pos){    return  (mask | (1<<pos));}
inline int resetBit(int mask,int pos){    return  (mask & ~(1<<pos));}
inline int toggleBit(int mask,int pos){    return  (mask ^ (1<<pos));}

void solve()
{
    int n;
    string st;
    cin>>n>>st;

    int res = n;
    int temp,niche,upore;
    for(int i=0;i<n;i++)
    {
        if(st[i]=='1')
        {
            niche = max(i+1,n-i);
            upore = max(i+1,n-i);
            temp = niche + upore;
            res = max(res,temp);
        }
    }
    cout<<res<<endl;

}

int main ()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin>>tc;
    while(tc--)
    {
        solve();
    }


    return 0;
}

