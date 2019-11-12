#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef pair<ll,ll> pli;
typedef pair<int,int> pii;
typedef pair<ld,ld> pld;

ll MOD=1000000007;
ll base=29;
ll MX=1e9;
ld pi=3.1415926535;
ll INF=400000000;

ll n;
ll a[500][500];


int main()
{
    fast;
    //freopen("input.txt","r",stdin);
    cin>>n;
    ll cnt=0;
    int i=1,j=1;
    while(cnt<n*n)
    {
        cnt++;
        a[i][j]=cnt;
        if(i==n&&j%2==1)
        {
            j++;
        }
        else if(i==1&&j%2==0)
        {
            j++;

        }
        else if(j%2==1)
        {
            i++;
        }
        else
            i--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
