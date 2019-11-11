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
const int N=1;

void solve()
{
    int n;
    cin>>n;

    int a,b,c;
    cin>>a>>b>>c;

    string s;
    cin>>s;

    int cur=0;
    vector<char> ans(n,'0');
    for(int i=0;i<n;++i)
    {
        if(s[i]=='S')
        {
            if(a)
                ans[i]='R',--a,++cur;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='R')
        {
            if(b)
                ans[i]='P',--b,++cur;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s[i]=='P')
        {
            if(c)
                ans[i]='S',--c,++cur;
        }
    }

    int x;
    if(n%2)
        x=n/2+1;
    else
        x=n/2;

    if(cur>=x)
    {
        cout<<"YES\n";

        for(int i=0;i<n;++i)
        {
            if(ans[i]=='0')
            {
                if(a)
                    ans[i]='R',--a;
                else if(b)
                    ans[i]='P',--b;
                else if(c)
                    ans[i]='S',--c;
            }
        }

        for(auto c:ans)
            cout<<c;
    }
    else
        cout<<"NO";
}

int32_t main()
{
    fast();

    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }

    return 0;
}

