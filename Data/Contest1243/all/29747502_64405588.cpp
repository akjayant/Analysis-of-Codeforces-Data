#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<unordered_set>
#include<deque>
#include<stack>
#include<algorithm>
#include<map>
#include<iterator>
#define lli long long int
#define mp make_pair
#define gcd(a,b)  __gcd(a,b)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define Pi  3.141592653589793
#define fo(i,n) for(lli i=0;i<(n);i++)
#define FO(i,x,n) for(lli i=(x);i<(n);i++)
#define FQ(i,x,n) for(lli i=(x);i<=(n);i++)
#define pf printf
#define pb push_back
#define sf scanf
#define vi vector<lli>
#define pi pair<lli,lli>
#define nl pf("\n")
using namespace std;
lli mod = 1e9 +7,test; 
lli max(lli a,lli b){return a>b?a:b;}
lli min(lli a,lli b){return a>b?b:a;}

vi fac;

void find_fac(lli n){ 
    lli N = n;
    lli count = 0; 
    while (!(n % 2)) { 
        n >>= 1; 
        count++; 
    } 
    if (count)  fac.push_back(2);
    lli maxi = sqrt(n);
    for(lli i = 3; i <= maxi; i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count)  fac.push_back(i); 
    }
    if(n>2 && n!= N ){fac.push_back(n);} 
} 
void solve(){
string s,t;
lli n; cin>>n;
find_fac(n);
// for(lli i : fac){
//     cout<<i<<endl;
// }
if(fac.size()==0){
    cout<<n<<endl; return;
}
if(fac.size()==1){
    cout<<fac[0]<<endl;return;
}
cout<<1<<endl;
}


int main(){
    lli t=1; 
    while(t--){
    solve();
    }
    return 0;
}