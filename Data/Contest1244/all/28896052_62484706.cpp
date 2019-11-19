#include<bits/stdc++.h>
/*---------------------Define--------------------*/
#define int long long
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname ""
#define pb push_back
#define mp make_pair
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
/*-------------------necesary---------------------*/
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------limit-------------------------*/
const int base  = 1e9+7;
const int oo = 1e6 + 10;
const int gh = 1e3 + 3 ;
const int inf = 1e15 + 5 ;
/*-----------------globalvari-----------------------*/
int n,m,k,q;
int a[oo];
/*-----------------code-----------------------*/


void input()
{
    //read
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];

}

int f[oo];

void cre()
{
    sort(a+1,a+n+1);
    for(int i = 1 ; i<=n ; i++)
        f[i] = f[i-1]+a[i];
}

void solve()
{
    cre();
    int ans = LONG_MAX;
    for(int i=1;i<=n;i++)
    {
        int k = m;
      //  cerr<<a[i]<<endl;
        if(f[n] - f[i] - (n-i)*a[i] <=k)
        {

            k-=(f[n] - f[i] - (n-i)*a[i]);

            int l = 1,r =a[i];

            while(l<=r)
            {
                int mid = (l+r)/2;
                int t = lower_bound(a+1,a+n+1,mid) - a - 1;
                int q = mid*t-f[t];
                if(q<=k) l = mid + 1;
                else  r = mid - 1;
            }

            ans = min (ans,abs(a[i] - r));
        }
        k=m;
        if( i*a[i] - f[i] <=k)
        {
            //cerr<<a[i]<<endl;
            k-=(i*a[i]-f[i]);
            int l = a[i],r = a[n];
            //cerr<<k<<endl;
            while(l<=r)
            {
                int mid = (l+r)/2;
                int t = upper_bound(a+1,a+n+1,mid) - a;
                //cerr<<mid<<" "<<t<<endl;
                //cerr<<t<<" "<<(n-t)<<endl;
                int q = f[n] - f[t-1] - mid*(n-t+1);
                //cerr<<mid<<" "<<t<<" "<<q<<endl;
                if(q<=k) r = mid - 1;
                else  l = mid + 1;
            }
            //cerr<<l<<endl;
            ans = min (ans,abs(a[i] - l));
        }
    }
    cout<<ans;
    //main code here :))
}

void ouput()
{

    //write
}

int32_t main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGES
    if (ifstream("test.txt"))
    {
        freopen("test.txt", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            //\freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    //#endif // ONLINE_JUDGES
    int t=1;
   // cin>>t;

    while(t--)
    {
    input();
    solve();
    ouput();
    }
}

//ilove??<3
