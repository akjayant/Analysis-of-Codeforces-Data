#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back                                
#define MP make_pair
#define LL long long int
#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define RFOR(i,a,b) for(long long int i = a ; i >= b ; i--)
#define FI first
#define SE second   
 
const LL MOD = 1000000007;
const long double PI = 3.14159265359;
const LL INF = 1e14;
 
char salpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char calpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 
LL gcd(LL a,LL b){if(a==0){return b;}return gcd(b%a,a);}
LL exp(LL b,LL p){if(p==0){return 1;}else if(p%2==0){return exp(b*b,p/2);}else{return b*exp(b*b,(p-1)/2);}}
LL mexp(LL b,LL p){if(p==0){return 1;}else if(p%2==0){return mexp((b*b)%MOD,p/2)%MOD;}else{return (b*mexp((b*b)%MOD,(p-1)/2))%MOD;}}
LL minv(LL a){return mexp(a,MOD-2);}
int isprime(LL n){for(LL i = 2 ; i*i<=n ; i++){if(n%i==0){return 0;}}return 1;}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    LL h = 0,v = 0;

    int in[n];
    FOR(i,0,n)
    {
        cin >> in[i];
    }
    sort(in,in+n);

    FOR(i,0,n)
    {
        if(i < n/2)
        {
            h += in[i];
        }
        else
        {
            v += in[i];
        }
    }

    cout << h*h + v*v << "\n";
 
    return 0;
}