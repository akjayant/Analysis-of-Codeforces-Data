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
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int pen = ((a-1)/c) + 1;
    int pencil = ((b-1)/d) + 1;

    if(pen+pencil > k)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<pen<<" "<<pencil<<endl;
    }

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

