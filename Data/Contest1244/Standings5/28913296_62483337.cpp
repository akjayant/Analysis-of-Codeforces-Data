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

ll n,p,w,d,x,y,z;


bool tryWin(ll wins)
{
    if(p<wins*w)   return false;
    if((p-wins*w)%d!=0)    return false;
    x = wins;
    y = (p-x*w)/d;
    if(x+y>n) return false;
    z = n - (x+y);
    return true;
}

bool tryDraw(ll draw)
{
    if(p<draw*d)   return false;
    if((p-draw*d)%w!=0)    return false;
    y = draw;
    x = (p-y*d)/w;
    if(x+y>n) return false;
    z = n - (x+y);
    return true;
}


void solve()
{
    scanf("%lld %lld %lld %lld",&n,&p,&w,&d);

    ll lim = 1e7;
    lim = min(lim,n);

    for(ll i=0;i<=lim;i++)
    {
        if(tryWin(i))
        {

            printf("%lld %lld %lld\n",x,y,z);
            return;
        }
        else if(tryDraw(i))
        {
            printf("%lld %lld %lld\n",x,y,z);
            return;
        }
    }
    printf("-1\n");
    return;

}

int main ()
{

    solve();


    return 0;
}

