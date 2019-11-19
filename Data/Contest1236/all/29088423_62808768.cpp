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

ll n,m,k;
set<ll> posrow[100100],negrow[100100],poscol[100100],negcol[100100];
ll fir[100100];
int main()
{
    fast;
    //freopen("input.txt","r",stdin);
    cin>>n>>m>>k;
    ll x,y;
    for(ll i=1;i<=k;i++)
    {
        cin>>x>>y;
        if(y==1)
            fir[x]++;
        posrow[x].insert(y);
        poscol[y].insert(x);
        negrow[x].insert(-y);
        negcol[y].insert(-x);
    }
    ll i=1,j=1;
    ll pos=1;
    ll res=1;
    ll temp;
    ll px1,pxn,py1,pym;
    px1=2;
    pxn=n;
    py1=1;
    pym=m;
    while(1)
    {
        //cout<<i<<" "<<j<<" "<<pos<<endl;
        if(pos==1)
        {
            if(posrow[i].lower_bound(j)==posrow[i].end())
            {
                temp=pym;
            }
            else
                temp=(*posrow[i].lower_bound(j))-1;
            temp=min(temp,pym);
            pym=temp-1;
            res+=abs(temp-j);
            if(temp==j)
                break;
            j=temp;
        }
        if(pos==2)
        {
            if(poscol[j].lower_bound(i)==poscol[j].end())
            {
                temp=pxn;
            }
            else
                temp=(*poscol[j].lower_bound(i))-1;
            temp=min(temp,pxn);
            pxn=temp-1;
            res+=abs(temp-i);
            if(temp==i)
                break;
            i=temp;
        }
        if(pos==3)
        {
            if(negrow[i].lower_bound(-j)==negrow[i].end())
             {
                 temp=py1;
             }
            else
                temp=-(*negrow[i].lower_bound(-j))+1;
            temp=max(py1,temp);
            py1=temp+1;
            res+=abs(temp-j);
            if(temp==j)
                break;
            j=temp;
        }
        if(pos==4)
        {
            if(negcol[j].lower_bound(-i)==negcol[j].end())
            {
                temp=px1;
            }
            else
                temp=-(*negcol[j].lower_bound(-i))+1;
            temp=max(px1,temp);
            px1=temp+1;
            res+=abs(temp-i);
            if(temp==i)
                break;
            i=temp;
        }
        //cout<<res<<endl;
        pos%=4;
        pos++;
    }
    if(res!=n*m-k)
    {
        ll ans=n;
        for(ll i=1;i<=n;i++)
        {
            if(fir[i])
            {
                ans=i-1;
                break;
            }
        }
        if(ans==n*m-k)
            res=n*m-k;
    }
    //cout<<res<<endl;
    if(res==n*m-k||k==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
