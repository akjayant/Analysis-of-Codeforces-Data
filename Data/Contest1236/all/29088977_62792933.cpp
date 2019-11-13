#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define int              long long
#define ll               long long
#define pii              pair<int,int>
#define pb               push_back
#define all(a)           a.begin(),a.end()
#define endl             '\n'
#define F                first
#define S                second
#define vi               vector<int>
#define len(s)           (int)s.length()
#define sz(s)            (int)s.size()
#define rep(i,a,b)       for(int i=a;i<b;i++)
#define bs               binary_search
#define lb               lower_bound
#define ub               upper_bound
#define mapi             map<int,int>
#define fat              998244353
#define hell            1000000007
#define N                100005
#define ios              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
using namespace std;
using namespace __gnu_pbds;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}


int power(int x,int y,int p) 
{ 
    int res = 1;       
    x = x % p;    
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;  
        x = (x*x) % p;   
    } 
    return res; 
} 


int solution()
{
    int a,b;
    cin>>a>>b;
    int x=power(2,b,hell);
    x+=hell;
    x--;
    x=x%hell;
    int ans=power(x,a,hell);
    cout<<ans;


}
 
signed main()
{
ios
int tests=1;
// cin>>tests;
while(tests--)
{
    solution();
}
return 0;
}
