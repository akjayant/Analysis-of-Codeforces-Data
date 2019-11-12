#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
using namespace std;
#define int     long long int
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define ppa     pair<pair<int,int>,int>
#define pap     pair<int,pair<int,int>>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define vpa     vector<pair<int,int>>
#define M       1000000007
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define endl    "\n"
#define v1s     vector<string>
#define all(v)  v.begin(),v.end()
#define S(v)    sort(v.begin(),v.end())
#define RS(v)   sort(v.rbegin(),v.rend())
#define R(v)    reverse(v.begin(),v.end())
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define T       int tc;cin>>tc;while(tc--)
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)      for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)      for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;

#define qqq 400005
#define div v
v1d div;

void pontifex_maximus(){
    T{
        int n;cin>>n;
        string s,t;cin>>s>>t;
        v1d p;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i])p.pb(i);
        }
        if(p.size()==1||p.size()>2){cout<<"No\n";continue;}
        if(p.size()==0){cout<<"Yes\n";continue;}
        // map<char,int>m;
        // m[s[p[0]]]++;m[t[p[0]]]++;m[s[p[1]]]++;m[t[p[1]]]++;
        if(t[p[0]]==t[p[1]]&&s[p[0]]==s[p[1]]&&t[p[0]]==s[p[0]])cout<<"Yes\n";
        else if(t[p[0]]==s[p[0]]&&t[p[1]]==s[p[1]])cout<<"Yes\n";
        else if(t[p[0]]==t[p[1]]&&s[p[0]]==s[p[1]])cout<<"Yes\n";
        else cout<<"No\n";
        // if(f)cout<<"No\n";
        // else cout<<"Yes\n";
    }

























}


int32_t main(){

    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
    #endif

    pontifex_maximus();
    
}



