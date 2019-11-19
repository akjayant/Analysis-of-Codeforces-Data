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
    in1(t);
    while(t--)
    {
        ll n,m,ans=0;
        ll a,b,c,d,k;
        in3(a,b,c);
        in2(d,k);
        n=(a+c-1)/c+(b+d-1)/d;
        if(n>k)
        cout << "-1\n";
        else
        {
            n=(a+c-1)/c;
            m=(b+d-1)/d;
            out2(n,m);
        }
    }
}