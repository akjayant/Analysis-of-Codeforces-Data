//RAB RAKHA

/* Code till every compiler has crashed */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

/*-----------------------------------------------------------------
                            Templates
----------------------------------------------------------------*/
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define in1(n) cin >> n;
#define in2(a,b) cin >> a >> b;
#define in3(a,b,c) cin >> a >> b >> c;
#define out1(n) cout << n << "\n";
#define out2(a,b) cout << a << " " << b << "\n";
#define out3(a,b,c) cout << a << " " << b << " " << c << "\n";
#define inputarr(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define printarr(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define initarr(a,n,x) for(int i=0;i<n;i++) a[i]=x;
#define veci vector<int>
#define seti set<int>
#define mapi map<int,int>
const int MOD=1e9+7;
/*-----------------------------------------------------------------
                            Templates
----------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a%b, b);
    return gcd(a, b%a);
}
void swap(ll &a, ll &b)
{
     b = a + b;
     a = b - a;
     b = b - a;
}
/*
if()
cout << "YES\n";
else
cout << "NO\n";
*/
int main()
{
    FASTIO
    int t=1;
    while(t--)
    {
        ll n,y,ans=0,i;
        in2(n,y);
        ll a[n];
        inputarr(a,n);
        sort(a,a+n);
        ll m0=a[0];
        ll m1=a[n-1];
        map<ll,ll> m;
        for(i=0;i<n;i++)
        m[a[i]]++;
        ll s=a[0],l=a[n-1];
        vector <ll> v;
        v.push_back(a[0]);
        for(i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            v.push_back(a[i]);
        }
        ll dh=1,df=v.size()-2;
        while(y>0)
        {
            if(s>=l)
            break;
            if(m[s]<=m[l])
            {
                if(y<m[s])
                break;
                if((v[dh]-v[dh-1])*m[s]>y)
                {
                    ll pos=y/m[s];
                    y-=pos*m[s];
                    s+=pos;
                    m[s]=m[s-pos];
                    m[s-pos]=0;
                }
                else
                {
                    m[v[dh]]+=m[s];
                    y-=(v[dh]-s)*m[s];
                    m[s]=0;
                    s+=v[dh]-s;
                    dh++;
                }
            }
            else
            {
                if(y<m[l])
                break;
                if((v[df+1]-v[df])*m[l]>y)
                {
                    ll pos=y/m[l];
                    y-=pos*m[l];
                    l-=pos;
                    m[l]=m[l+pos];
                    m[l+pos]=0;
                }
                else
                {
                    m[v[df]]+=m[l];
                    y-=(l-v[df])*m[l];
                    m[l]=0;
                    l+=v[df]-l;
                    df--;
                }
            }
        }
        ans=l-s;
        if(ans<0)
        ans=0;
        out1(ans);
    }
}