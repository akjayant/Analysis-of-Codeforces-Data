#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define M 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll fib[100001], i,ans = 1, cu = 0, cv = 0;
    fib[1] = 1;
    fib[2] = 2;
    fib[0] = 1;
    for(i=3;i<100001;i++)
        fib[i] = (fib[i-1] + fib[i-2])%M;
    string s;
    cin>>s;
    ll n = s.length();
    for(i=0;i<n;i++)
    {
        if(s[i] =='m' or s[i] =='w')
            ans = 0;
        if(s[i] == 'u')
            cu++;
        else if(s[i] == 'n')
            cv++;
        if(s[i] != 'u')
        {
            ans = (ans*fib[cu])%M;
            cu=0;
        }
        if(s[i] != 'n')
        {
            ans = (ans*fib[cv])%M;
            cv = 0;
        }
    }
    ans = (ans*fib[cu])%M;
    ans = (ans*fib[cv])%M;
    cout<<ans;
        
        
    return 0;
}
