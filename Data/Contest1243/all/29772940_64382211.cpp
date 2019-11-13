#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1<<(i))))
#define setbit1(n,i) ((n)|(1<<(i)))
#define togglebit(n,i) ((n)^(1<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define fi first
#define se second
#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d%d",&a,&b)
#define PI (acos(-1))
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1000000007)
#define asz 500005
ll a[100005];
int main()
{
    fastread;
    ll T=1;
    cin>>T;
    for(ll qq=1;qq<=T;qq++)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        ll ind=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])a[ind++]=i;
        }
        if(ind%2||ind>2)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(ind==0||s[a[0]]==s[a[1]]&&t[a[0]]==t[a[1]])
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}

