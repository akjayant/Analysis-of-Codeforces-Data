/*enjoy karo yaar*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     F            first
#define     S            second

const int inf=1e18,M=1e9+7;
const int N=1e5+5;

vector<int> fib(N);

void compute()
{
    fib[0]=fib[1]=1;
    for(int i=2;i<N;++i)
        fib[i]=(fib[i-1]%M+fib[i-2]%M+M)%M;
}

void solve()
{
    string s;
    cin>>s;

    int n=s.length();
    for(int i=0;i<n;++i)
    {
        if(s[i]=='m' || s[i]=='w')
        {
            cout<<0;
            return;
        }
    }

    compute();

    int ans=1,cnt=1;
    for(int i=1;i<n;++i)
    {
        if(s[i]==s[i-1] && (s[i]=='u' || s[i]=='n'))
        {
            ++cnt;

            if(i==n-1)
                ans=(ans%M*fib[cnt]%M)%M;
        }
        else
        {
            ans=(ans%M*fib[cnt]%M)%M;
            cnt=1;
        }
    }

    cout<<ans%M;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

