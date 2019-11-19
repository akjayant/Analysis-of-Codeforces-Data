#include<bits/stdc++.h>

using namespace std;

#define LCM(a,b)                (a / __gcd(a,b) ) *b
#define GCD(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define LL                      long long
#define ULL                     unsigned long long
#define pb                      push_back
#define tcase                   cout<<"Case "<<C++<<": ";
#define all(a)                  a.begin(),a.end()
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end
#define ABS(x)                  ((x)<0?-(x):(x))
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define PI                      acos(-1.0)
#define ff                      first
#define ss                      second
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define FastRead                ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(x, l, r)            for (int x = l; x<=r; ++x)
#define REP(x,r)                for (int x = 0; x <r; ++x)
#define NN                      cout<<"\n";
#define NNN                     cout<<"\n------------------------------\n";
#define mk                      make_pair
//***********************************************************************//
//                      SHAHED AHMED, CSE'15, IUT                        //
//***********************************************************************//

LL x[100010];
LL y[100010];
LL c[100010];
LL s[100010];


vector<pair<LL,pair<LL,LL> > > v;


LL parent[100010];
LL rnk[100010];

LL elec[100010];

void make_set(LL v) {
    parent[v] = v;
    rnk[v] = 0;
    elec[v]=0;
}

LL find_set(LL v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(LL a, LL b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;

        elec[a] = max(elec[a],elec[b]);


        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
vector<pair<LL,LL> > ans1;
vector<LL> ans2;

LL cc=0;

void solve()
{
    for(LL i=0;i<v.size();i++)
    {

        //cout<<v[i].ff<<" "<<v[i].ss.ff<<" "<<v[i].ss.ss<<"...\n";

        if(v[i].ss.ff == v[i].ss.ss)
        {
            LL u = find_set(v[i].ss.ff);

            if(elec[u]!=1)
            {
                elec[u]=1;
                ans2.pb(v[i].ss.ff);
                cc+=v[i].ff;
            }

            continue;
        }

        LL x,y,cost;
        cost = v[i].ff;
        x= find_set(v[i].ss.ff);
        y= find_set(v[i].ss.ss);


        if(x==y) continue;

        if(elec[x]==1 && elec[y]==1) continue;
        else
        {
            //cout<<"#\n";
            union_sets(x,y);
            ans1.pb({v[i].ss.ff,v[i].ss.ss});
            cc+=v[i].ff;
        }


    }



}

int main()
{
    FastRead
    LL n;
    cin>>n;

    for(LL i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        make_set(i);
    }

    for(LL i=1;i<=n;i++)
    {
        cin>>s[i];
        v.pb(mk(s[i],mk(i,i)));
    }

    for(LL i=1;i<=n;i++)
    {
        cin>>c[i];
    }



    for(LL i=1;i<=n;i++)
    {
        for(LL j=i+1;j<=n;j++)
        {
            LL cost = ABS(x[i]-x[j]) + ABS(y[i]-y[j]);
            cost*=(c[i]+c[j]);
            v.pb(mk(cost,mk(i,j)));
        }
    }

    sort(all(v));

    solve();

    cout<<cc<<"\n";
    cout<<ans2.size()<<"\n";
    for(auto u:ans2)
    {
        cout<<u<<" ";
    }
    cout<<"\n";


    cout<<ans1.size()<<"\n";

    for(auto u:ans1)
    {
        cout<<u.ff<<" "<<u.ss<<"\n";
    }



}
