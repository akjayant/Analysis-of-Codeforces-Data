#include <bits/stdc++.h>
using namespace std;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld long double
long double PI =3.14159265358979323846;


const ll modo=1e9+7;
const ll inf=1e15;
const ll ms=(1e3*2) +5;
int dad[ms];
int siz[ms];
ll ar[ms][2];
ll br[ms];
ll kr[ms];
int findpar(int i)
{
    if(dad[i]==i)return i;
    return dad[i]=findpar(dad[i]);
}
void unionn(int a,int b)
{
    if(siz[b]>siz[a])swap(a,b);
    dad[b]=a;
    siz[a]+=b;
}
vector<int> one;
vector<pair<int,int>> two;
vector<pair<ll,pair<int,int>>> ss;
//set<pair<ll,pair<int,int>>> ss;
int main()
{
    idfc;
    int n;
    cin>>n;
    int i;
    for(i=0;i<=n;i++)
    {
        dad[i]=i;siz[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        cin>>ar[i][0]>>ar[i][1];
    }
    for(i=1;i<=n;i++)
    {
        cin>>br[i];
        ss.pb({br[i],{0,i}});
    }
    for(i=1;i<=n;i++)
    {
        cin>>kr[i];
    }
    int j;
    ll dd;
    ll tt;
    ll pp;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j)
            {
                tt=kr[i]+kr[j];
                dd=abs(ar[i][0]-ar[j][0])+abs(ar[i][1]-ar[j][1]);
                pp=tt*dd;
                ss.pb({pp,{i,j}});
            }
        }
    }
    sort(ss.begin(),ss.end());
    int siz=ss.size();
    int u;int v; int a,b;
    ll ans=0;
    for(i=0;i<siz;i++)
    {
        dd=ss[i].first;
        u=ss[i].second.first;
        v=ss[i].second.second;
        a=findpar(u);
        b=findpar(v);
       // cout<<dd<<" "<<u<<" "<<v<<endl;
        if(a!=b)
        {
            if(u==0)
            {
                one.pb(v);
            }
            else{
                two.pb({u,v});
            }
            unionn(a,b);
            ans+=dd;
        }
    }
    cout<<ans<<"\n";
    cout<<one.size()<<"\n";
    for(int ii:one)cout<<ii<<" ";
    cout<<"\n";
    cout<<two.size()<<"\n";
    for(auto ii:two)cout<<ii.first<<" "<<ii.second<<"\n";
    return 0;
}