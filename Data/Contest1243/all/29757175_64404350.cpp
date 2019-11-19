#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <cmath>
#include <set>
#include <iterator>
#include <deque>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull min(ull x, ull y){ if (x<y) return x; return y;}
ull max(ull x, ull y){ if (x<y) return y; return x;}
ll min(ll x, ll y){ if (x<y) return x; return y;}
ll max(ll x, ll y){ if (x<y) return y; return x;}
double min(double x, double y){ if (x<y) return x; return y;}
double max(double x, double y){ if (x<y) return y; return x;}
ull gcd(ull x, ull y){
    if (!x) return y;
    if (!y) return x;
    if (x>y) swap(x,y);
    return gcd(x, y%x);
}
ull inv(ull a, ull c){ // a,c are coprime and a<c
    if (a==1){
        return 1;
    }
    return ((c-(c/a))*inv(c%a,c))%c;
}

vector<ll> pf(ll n){
    vector<ll> p;
    ll i = 2;
    while (i <= sqrt(n)){
        if (n%i==0) p.push_back(i);
        while (n%i==0){
            n/=i;
        }
        i++;
    }
    if (n>=2) p.push_back(n);
    return p;
}

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> pfs = pf(n);
    if (pfs.size()==1){
        cout<<pfs[0]<<"\n";
    }
    else{
        cout<<1<<"\n";
    }

    
}



