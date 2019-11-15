#include <bits/stdc++.h>
#define ENDL '\n'
#define F first
#define S second
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FLOOR(a,b) (a-a%b) / b
#define CEIL(a,b) (a%b==0) ? a/b : FLOOR(a,b) + 1
#define NEXT(a) next_permutation(ALL(a))
#define T = 100000
#define N = 1000000000000000000
#define RANDOM(a) (rand()%a) + 1
#define TEST_CASES 20

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;


lli MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    vector<lli> fib(1e5+5);
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2;i<=1e5;++i)
        fib[i] = (fib[i-1]+fib[i-2])%MOD;
    lli ans=1;
    if(s[0]=='m'||s[0]=='w')
    {
        cout<<0<<ENDL;
        return 0;
    }
    lli u=0,n=0;
    if(s[0]=='u') ++u;
    if(s[0]=='n') ++n;
    for(int i=1;i<s.size();++i)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0<<ENDL;
            return 0;
        }
        if(s[i]=='u')
        {
            ++u;
            if(s[i-1]=='n')
            {
                ans = (ans*fib[n])%MOD;
                n = 0;
            }
            continue;
        }
        if(s[i]=='n')
        {
            ++n;
            if(s[i-1]=='u')
            {
                ans = (ans*fib[u])%MOD;
                u = 0;
            }
            continue;
        }
        if(s[i-1]=='u')
        {
            ans = (ans*fib[u])%MOD;
            u = 0;
        }
        if(s[i-1]=='n')
        {
            ans = (ans*fib[n])%MOD;
            n = 0;
        }
    }
    ans = (ans*fib[u])%MOD;
    ans = (ans*fib[n])%MOD;
    cout<<ans<<ENDL;
    return 0;
}
