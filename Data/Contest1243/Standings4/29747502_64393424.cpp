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
string s,t;
lli n; cin>>n;
cin>>s>>t;
lli idx = n-1,f,l,moves = 2*n;
vector<pi > ans;
while(idx >= 0){
    // cout<<idx<<endl;
    l = idx;
    f = -1;
    if(idx== 0 && s[idx] != t[idx]){
        break;
    }
    if(s[idx] == t[idx]){
                idx--;
        continue;
    }
    fo(i,l){
        if(s[i] == s[idx]){
            f = i; break;
        }
    }
    if(f!=-1){
        char c = s[f];
        s[f] = t[idx];
        t[idx] = s[f];
                ans.push_back(mp(f,idx));
         idx--; 
        // cout<<s[f] <<" "<<s[idx]<<endl;
        // cout<<" f is "<<f<<" idx = "<<idx<<endl;
        continue;
    }
    if(f==-1){
        fo(i,idx){
            if(t[i]==s[idx]){
                f= i; break;
            }
        }
        if(f==-1){
            break;
        }
        char c = t[f];
        t[f] = s[f];
        s[f] = c;
        ans.push_back(mp(f,f));
    }
}
if(idx!=-1){
    cout<<"No\n"; return;
}
cout<<"Yes\n";
cout<<ans.size()<<endl;
for(pi p : ans){
    cout<<p.first+1<<" "<<p.second+1<<endl;
}

}


int main(){
    lli t=1; 
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}