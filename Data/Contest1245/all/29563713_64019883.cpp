#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define sc second
#define fr first
#define ll long long

priority_queue < pair < ll ,pair< ll ,ll > > > pq;
ll ck[100005],pos[10000][2],ara[10000],cst[10000];

pair < ll,pair < ll,ll > > pr;
pair < ll,ll > tanu;

queue < ll > ph;
queue < pair <ll,ll> > con;

int main()
{
    ll n,m,i,j,k,a,b,c,x,y,z;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld",&pos[i][0],&pos[i][1]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&ara[i]);
        pq.push(mp(-ara[i],mp(i,i)));

    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&cst[i]);
    }
    z=n;
    x=0;
    y=0;
    while(!pq.empty() && z>0)
    {
        pr=pq.top();
        pq.pop();
        a=pr.sc.fr;
        if(ck[a])
            continue;
        pr.fr=-pr.fr;
        x+=pr.fr;
        if(pr.sc.fr==pr.sc.sc)
        {
            ph.push(pr.sc.fr);
        }
        else
        {
            con.push(mp(pr.sc.fr,pr.sc.sc));
        }
        a=pr.sc.fr;
        ck[a]=1;
        z--;
        for(i=1;i<=n;i++)
        {
            if(ck[i])
                continue;
            b=abs(pos[a][0]-pos[i][0])+abs(pos[a][1]-pos[i][1]);
            b*=(cst[a]+cst[i]);
            pq.push(mp(-b,mp(i,a)));
        }

    }
    cout<<x<<endl;
    cout<<ph.size()<<endl;
    while(!ph.empty())
    {
        a=ph.front();
        printf("%lld ",a);
        ph.pop();
    }
    cout<<endl;
    cout<<con.size()<<endl;
    while(!con.empty())
    {
        tanu=con.front();
        con.pop();
        printf("%lld %lld\n",tanu.fr,tanu.sc);
    }
}
