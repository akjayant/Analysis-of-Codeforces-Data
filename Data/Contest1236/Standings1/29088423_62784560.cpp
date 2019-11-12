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

ll MOD=998244353;
ll base=29;
ll MX=1e9;
ld pi=3.1415926535;
ll INF=400000000;




int main()
{
    fast;
    //freopen("input.txt","r",stdin);
    int t,a,b,c;
    cin>>t;
    while(t--)
    {
        int res=0;
        cin>>a>>b>>c;
        int temp=min(c/2,b);
        res+=temp*3;
        c-=2*temp;
        b-=temp;
        temp=min(b/2,a);
        res+=3*temp;
        cout<<res<<endl;

    }

    return 0;
}
