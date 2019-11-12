/*********************************************JMD**********************************************/
//                                  |\  |     | |   |   /\                                   //
    //                              | \ |     | |---|  /--\                              //
        //                          |  \| |___| |   | /    \1999                     //
/*******************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

typedef  int ll;
typedef unsigned long long int ull;

#define mp make_pair
#define pb push_back
#define pf push_front
#define ss second
#define ff first
#define mem(x,val) memset(x,val,sizeof(x))
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define f(i,n) forr(i,0,n)
#define sz(x) ll((x).size())
#define all(x) ((x).begin(),(x).end())
#define asc(x) ((int)(x))
#define precision(x) cout<<fixed<<setprecision((x));

const ll mod=1e9 + 7;

/*******************************************************************************************/

void solve()
{
    ll n;
    cin>>n;

    ll a[n][n];
    ll curr=1;

    f(i,n)
    {
        if(i%2==0)
        {
            f(j,n) a[i][j]=curr++;
        }
        else
        {
            for(ll j=n-1;j>=0;j--) a[i][j]=curr++;
        }
    }

    f(i,n)
    {
        f(j,n) cout<<a[j][i]<<" ";
        cout<<endl;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    //cin>>t;
    clock_t launch=clock();

    while(t--)
    {
        solve();
    }

    clog<<((long double)(clock()-launch)/CLOCKS_PER_SEC)<<"\n";
}
