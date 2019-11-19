#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

int t;
int l,r;
vector<pii> v;
int p2[50],p3[50];

int32_t main()
{
    IOS
    p2[0]=1,p3[0]=1;
    for (int i=1;i<=35;i++) p2[i]=p2[i-1]*2,p3[i]=p3[i-1]*3;
    cin>>t;
    while (t--)
    {
        v.clear();
        cin>>l>>r;
        int ok=0;
        if (l==0&&r==0)
        {
            cout<<1<<endl;
            continue;
        }
        if (l==0) l++,ok=1;
        int high1=0,high2=0;
        for (int i=35;i>=0;i--)
        {
            if ((r&(1ll<<i)))
            {
                high1=max(high1,i);
            }
            if ((l&(1ll<<i)))
            {
                high2=max(high2,i);
            }
        }
        //cout<<high1<<' '<<high2<<endl;
        if (high1==high2)
        {
            if (ok) cout<<2*r+1<<endl;
            else cout<<0<<endl;
        }
        else
        {
            int now=0;
            for (int i=high2;i>=0;i--)
            {
                if (i==high2) ;
                else if (l&(1ll<<i)) ;
                else v.pb(mkp((now&l)^(1ll<<i),i));
                now|=(1ll<<i);
            }
            v.pb(mkp(l,0));
            now=0;
            for (int i=high1;i>=0;i--)
            {
                if (i==high1) ;
                else if (r&(1ll<<i)) v.pb(mkp((now&r),i));
                else ;
                now|=(1ll<<i);
            }
            v.pb(mkp(r,0));
            for (int i=high2+1;i<=high1-1;i++)
            {
                v.pb(mkp(1ll<<i,i));
            }
            //cout<<sz(v)<<endl;

            int ans=0,N=sz(v);
            for (int i=0;i<N;i++)
            {
                for (int j=0;j<i;j++)
                {
                    now=0;
                    if ((v[i].F&v[j].F)!=0) continue;
                    if (v[i].S<v[j].S)
                    {
                        for (int k=v[i].S;k<v[j].S;k++)
                            if ((((1ll<<k)&v[i].F))==0) now++;
                        ans+=(p2[now]*p3[v[i].S]);
                    }
                    else
                    {
                        for (int k=v[j].S;k<v[i].S;k++)
                            if ((((1ll<<k)&v[j].F))==0) now++;
                        ans+=(p2[now]*p3[v[j].S]);
                    }
                    //cout<<v[i].F<<' '<<v[i].S<<' '<<v[j].F<<' '<<v[j].S<<' '<<ans<<endl;
                }
            }
            ans*=2;
            if (ok==1) ans+=r*2+1;
            cout<<ans<<endl;
        }
    }
}

