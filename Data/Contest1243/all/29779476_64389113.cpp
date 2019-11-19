#include<bits/stdc++.h> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define forn(i,o,n) for(int i=o;i<n;i++)
#define int long long
#define endl "\n"
#define mod 1000000007
#define double long double
#define pb push_back
#define swap(x,y) (x^=y^=x^=y)
using namespace std;
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}
bool isPrime(int n){
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
int32_t main(){
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout); 
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        int g=1;
        int f=0;
        if(isPrime(n)){
            cout<<n;
            return 0;
        }
        for (int i = 2; i*i <=n; ++i)
        {
            if(n%i==0){
                if(f==0){
                    g=__gcd(i,n/i);
                    f++;
                }
                else g=__gcd(g,__gcd(i,n/i));
            }
        }
        cout<<g;
        cout<<endl;
    }
}