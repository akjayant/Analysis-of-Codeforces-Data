#include<bits/stdc++.h>
#pragma GCC optimize ("-O3")
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define diff(a,b) (a>b?a-b:b-a)
const int N=1e5+5;
void pairsort(int a[], int b[], int n){
    pair<int, int> pairt[n];
    for (int i = 0; i < n; i++) 
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    sort(pairt, pairt + n);
    for (int i = 0; i < n; i++) 
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}
int isPrime(int n){
    if(n < 2)
        return 0;
    if(n < 4)
        return 1;
    if(n % 2 == 0 or n % 3 == 0)
        return 0;
    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 or n % (i+2) == 0)
            return 0;
    return 1;
}
long long C(int n, int r) {
    if(r>n-r) 
        r=n-r;
    long long ans=1;
    for(int i=1;i<=r;i++){
        ans*=n-r+i;
        ans/=i;
    }
    return ans;
}
int mod = 1e9+7;
int modexpo(int x,int p){
    int res = 1;
    x = x%mod;
    while(p){
        if(p%2)
            res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}
int n,a[N],b[N],c[N],x,y,vis[N],root,d[3],p,ans=1e18,e[N];
vector<int> v[N],vv;
int32_t main()
{
    IOS;
    cin>>n,vv.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<n;i++)
        cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>2)
        {
            cout<<-1;
            return 0;
        }
        if(v[i].size()==1)
            root=i;
    }
    int cnt=6;
    d[0]=1,d[1]=2,d[2]=3;
    while(cnt--)
    {
        int cnt1=n,tans=0;
        x=root,p=0;
        memset(vis,0,sizeof(vis));
        while(cnt1)
        {
            vis[x]=d[p],cnt1--;
            if(d[p]==1)
                tans+=a[x],vv[x]=1;
            if(d[p]==2)
                tans+=b[x],vv[x]=2;
            if(d[p]==3)
                tans+=c[x],vv[x]=3;
            for(int i=0;i<v[x].size();i++)
                if(!vis[v[x][i]])
                {
                    x=v[x][i],p=(p+1)%3;
                    break;
                }
        }
        if(tans<ans)
        {
            for(int i=1;i<=n;i++)
                e[i]=vv[i];
            ans=tans;
        }
        next_permutation(d,d+3);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        cout<<e[i]<<" ";
    return 0;
}