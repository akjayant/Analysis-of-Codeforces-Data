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
        ll n,i,ans=0;
        in1(n);
        string s;  cin>>s;
        ll count=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
            count++;
        }
        ll left=-1,right=-1;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                left=i;
                break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                right=i;
            }
        }
        if(count==0)
        ans=n;
        else if(count==n)
        ans=2*n;
        else if(s[0]=='1'||s[n-1]=='1')
        ans=2*n;
        else
        {
            ans=max(2*(n-right),2*(left+1));
            ans=max(ans,2*(n-left));
            ans=max(ans,2*(right+1));
            ans=max(ans,n+count);
        }
        // if(left==0||right==n-1&&count>0)
        // ans=2*n;
        // else
        // {
        //     if(count==0)
        //     ans=n;
        //     else
        //     {
        //     right=n-1-right;
        //     ans=max(n+count,2*right);
        //     ans=max(ans,2*left);
        //     }
                
        //     }
        out1(ans);
    }
}