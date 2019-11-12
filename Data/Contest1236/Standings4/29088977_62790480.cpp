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
#define hell             1000000007
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

int solution()
{
    int n;
    cin>>n;
    int gr[n][n];
    int x=0;
    int y=0;
    for (int i = 0; i < n*n; ++i)
    {
        gr[x][y]=i+1;
        if(y%2==0){
            x++;
            if(x==n){
                x=n-1,y++;
            }
        }
        else{
            x--;
            if(x==-1){
                x=0;y++;
            }
        }

    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<gr[i][j]<<" ";
        }
        cout<<endl;
    }
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
