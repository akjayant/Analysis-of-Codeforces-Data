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
        int pos=1;
        vii v;
        for(int i=0;pos&&i<n;i++)
        {
            if(s[i]!=t[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    if(s[j]==s[i])
                    {
                        swap(s[j],t[i]);
                        v.push_back(ii(j+1,i+1));
                        break;
                    }
                }
                if(s[i]!=t[i])
                {
                    for(int j=i+1;j<n;j++)
                    {
                        if(t[j]==s[i])
                        {
                            v.push_back(ii(j+1,j+1));
                            v.push_back(ii(j+1,i+1));
                            swap(s[j],t[j]);
                            swap(t[i],s[j]);
                            break;
                        }
                    }
                }
                if(s[i]!=t[i])pos=0;
            }
        }
        if(pos)
        {
            cout<<"Yes"<<endl;
            cout<<v.size()<<endl;
            for(auto x:v)cout<<x.fi<<' '<<x.se<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}

