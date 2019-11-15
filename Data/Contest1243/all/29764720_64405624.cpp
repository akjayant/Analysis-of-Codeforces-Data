#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

int task,n;
string a,b;

main()
{
   // freopen("test.inp","r",stdin);
    cin >> task;
    while(task--)
    {
        int dem=0;
        cin >> n;
        cin >> a >> b;
        string s=' '+a;
        string t=' '+b;
        forinc(i,1,n) if(s[i]!=t[i]) dem++;
        if(dem==0)
        {
            cout << "NO\n";
            continue;
        }
        if(dem>=3)
        {
            cout << "NO\n";
            continue;
        }
        if(dem==1)
        {
            cout << "NO\n";
            continue;
        }
        if(dem==2)
        {
            int pos=0;
            forinc(i,1,n) if(s[i]!=t[i])
            {
                pos=i;
                break;
            }
            int pos1=0;
            fordec(i,n,1) if(s[i]!=t[i])
            {
                pos1=i;
                break;
            }
            bool ok=true;
            swap(s[pos],t[pos1]);
            forinc(i,1,n) if(s[i]!=t[i])
            {
                ok=false;
                break;
            }
            swap(s[pos1],t[pos]);
            swap(s[pos],t[pos1]);
            bool ok1=true;
            forinc(i,1,n) if(s[i]!=t[i])
            {
                ok1=false;
                break;
            }
            if(ok)
            {
                cout << "YES\n" ;
                continue;
            }
            if(ok1)
            {
                cout << "YES\n" ;
                continue;
            }
            cout<<"NO"<<"\n";
        }
    }
}
