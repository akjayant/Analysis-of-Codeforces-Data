/*

প্রশ্ন জাগে আমার অদৃশ্য দেয়ালে
জানা অজানার গুণিন দেখে পরিশেষে
স্মৃতির প্রতিচ্ছবি তুমি সকল
অচেনার রুপকার আলেয়া অলংকারের
অদেখা স্বর্নকার স্বপ্নদেব
শোনো এই হাহাকার

-স্বপ্নদেব, VIBE

*/



#include<bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define ll long long
#define fr(I,M,N) for(I=M;I<=N;I++)
#define fr_(I,M,N) for(I=M;I>=N;I--)
#define re return
#define sfn cin>>n
#define bal pf("bal\n")
#define pb push_back
#define ins insert
#define sz(X) X.size()
#define xx first
#define yy second
#define skip continue
#define memo(X,N) memset(X,N,sizeof(X))
#define all(X) X.begin(),X.end()
#define mp make_pair
#define pi acos(-1)


/*
#define nMX 5000000
#define pMX 500000
int pr[pMX+1],prnum[nMX+1];

int sieve()
{
    int i,j;
    for(i=1;i<=nMX;i++)
        prnum[i]=i+1;
    for(i=1;i<=nMX;i++)
        if(prnum[i]!=-1)
            for(j=2*prnum[i]-1;j<=nMX;j+=prnum[i])
                    prnum[j]=-1;
    j=0;
    for(i=1;i<=nMX;i++)
        if(prnum[i]!=-1)
            pr[++j]=prnum[i];
    re j;
}*/

/*ll m_ncr[10001][10001];
ll ncr(ll i,ll j)
{
    if(j==1) re i;
    if(i==j) re 1;
    if(m_ncr[i][j]!=-1) re m_ncr[i][j];
    re m_ncr[i][j]=ncr(i-1,j) + ncr(i-1,j-1);
}*/

/*ll m_fact[21];
ll fact(ll i)
{
    if(i==1 || i==0) re 1;
    if(m_fact[i]!=-1) re m_fact[i];
    re m_fact[i]=i*fact(i-1);
}*/

ll mod=1e9+7;

ll mem[100005][4][4];

ll calc(ll i, ll b, ll td, ll n)
{
    if(i>=n) re 1;
    if(mem[i][b][td]!=-1) re mem[i][b][td];
    ll rt;
    if(td)
    {
        mem[i][b][td]=(calc(i+1, !b, 0, n)%mod);
        if(mem[i][b][td]<0) mem[i][b][td]+=mod;
        re mem[i][b][td];
    }
    else
    {
        rt=calc(i+1, !b, 0, n)%mod;
        rt+=(calc(i+1, b, 1, n)%mod);
        rt%=mod;
        if(rt<0) rt+=mod;
        re mem[i][b][td]=rt;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll int i,j,x,y,n,m,cnt=0,k,g,flg,t;
    cin>>n>>m;
    fr(i,0,m)
    {
        fr(j,0,3) fr(k,0,3) mem[i][j][k]=-1;
    }
    x=(calc(1,0,0,m)+calc(1,1,0,m))%mod;
    //cout<<m<<" "<<x<<endl;
    x-=2;
    if(x<0) x+=mod;
    fr(i,0,n)
    {
        fr(j,0,3) fr(k,0,3) mem[i][j][k]=-1;
    }
    y=(calc(1,0,0,n)+calc(1,1,0,n))%mod;
    //cout<<n<<" "<<y<<endl;
    if(y<0) y+=mod;
    x+=y;
    x%=mod;
    if(x<0) x+=mod;
    cout<<x;
}
