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


void solve(){
lli n; cin>>n;
lli a[n];
fo(i,n){
    cin>>a[i];
}
sort(a,a+n,greater<lli>());
lli ans = 1,mini = a[0];
FO(i,1,n){
    mini = a[i];
   ans = max(ans, min(i+1,mini));
}
cout<<ans<<endl;
}


int main(){
    lli t=1; 
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}