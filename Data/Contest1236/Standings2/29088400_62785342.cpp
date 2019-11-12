#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define lli long long int
#define F first
#define S second
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MAX1 998244353
#define MAX2 1000000007
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#define input(data,n,command) for(lli i=0;i<n;i++){lli tmp;cin>>tmp;data.pb(tmp);command}
#define sort(a) sort(a.begin(),a.end());
#define display(a) for(lli i = 0 ;i<a.size();i++){cout<<a[i]<<" ";} cout<<endl;
#define rep(i,n,p) for(lli i = 0;i<n;i= i +p)
#define endl "\n"

//Written By GHATAK...
/*--------------------------------------------------------------------*/
//vector<pair<lli,lli>>adj[300010];

int main()
{
    ios
    lli T=1;
    cin>>T;
    while(T--)
    {
        //start from here
        lli a,b,c;
        cin>>a>>b>>c;
        lli ans = 0;
        while(1)
        {
            if((b>=1)&&(c>=2))
            {
                ans += 3;
                b--;
                c = c-2;
            }
            else if((a>0)&&(b>=2))
            {
                ans +=3;
                a--;
                b = b-2;
            }
            else
            {
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*-----------------------------------------------------------------------*/
/*
--->  reverse(vec.begin(),vec().end());
*/