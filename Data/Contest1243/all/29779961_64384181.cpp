#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define deb1(x)                cout<<#x<<": "<<x<<endl
#define deb2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define deb3(x, y, z)          cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define deb4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define deb5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define deb6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

#define MAXN 100010
#define MOD 1000000007
using namespace std;

int main(){
    
    ll n;
    cin>>n;
    ll t1=sqrt(n);
    
    set<ll> s;
    for(int i=2;i<=t1;i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    
    s.insert(n);
    ll t2=0;
    for(auto it=s.begin();it!=s.end();it++){
        t2 = __gcd(t2,*it);
    }
    cout<<t2<<endl;
    
    
    return 0;
}
