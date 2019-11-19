#include <bits/stdc++.h>
#define ll int64_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
/*
bool sv[1000000];
void fillsv(ll x)
{
    memset(sv,true,sizeof(sv));
    sv[0]=sv[1]=false;
    for(ll p=2;p*p<=x;p++)
        if(sv[p]==true)
            for(ll i=p*p;i<=x;i+=p)
                sv[i]=false;
}*/
inline ll max(ll a,ll b){return (a>b)?a:b;}
inline ll min(ll a,ll b){return (a<b)?a:b;}
inline ll max3(ll a,ll b,ll c){return max(a,max(b,c));}
inline ll min3(ll a,ll b,ll c){return min(a,min(b,c));}
ll gcd(ll a,ll b)
{
    return (a%b==0)?b:gcd(b,a%b);
}
ll pow3(ll a,ll b, ll m=1000000007)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}
/*struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1=hash<T1>{}(p.first);
        auto hash2=hash<T2>{}(p.second);
        return hash1^hash2;
    }
};*/
/*struct dsf
{
    ll n;
    vector<ll> p,r,s,e;
    dsf(ll N)
    {
        n=N;
        s.assign(N,0);
        p.assign(N,0);
        r.assign(N,1);
        e.assign(N,0);
        for(int i=0;i<N;i++)
            p[i]=i;
    }
    ll FindSet(ll i)
    {
        return (p[i]==i)?i:(p[i]=FindSet(p[i]));
    }
    bool isSame(ll i,ll j)
    {
        return FindSet(i)==FindSet(j);
    }
    void Union(ll i,ll j)
    {
        link(FindSet(i),FindSet(j));
    }
    void link(ll i,ll j)
    {
        if(i!=j)
        {
            if(r[i]>=r[j])
            {
                p[j]=i;
                s[i]+=s[j];
                e[i]+=e[j];
                if(r[i]==r[j])
                    r[i]++;
            }
            else
            {
                p[i]=j;
                s[j]+=s[i];
                e[j]+=e[i];
            }
        }
    }
    void edf()
    {
        for(int i=0;i<n;i++)
            e[i]/=2;
    }
    void disp()
    {
        for(ll i=0;i<n;i++)
            cout<<p[i]<<' ';
        cout<<endl;
    }
    void diss()
    {
        for(ll i=0;i<n;i++)
            cout<<s[i]<<' ';
        cout<<endl;
    }
    void dise()
    {
        for(ll i=0;i<n;i++)
            cout<<e[i]<<' ';
        cout<<endl;
    }
};*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //fillsv(1000000);
    int q=1;
    cin>>q;
    while(q--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int np=ceil(a*1.0/c);
        int nc=ceil(b*1.0/d);
        if(np+nc>k)
            cout<<"-1\n";
        else cout<<np<<" "<<nc<<endl;
    }
    return 0;
}