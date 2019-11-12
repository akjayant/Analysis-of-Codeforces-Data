// Siddhant Gautam
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long ll
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define bitcount __builtin_popcountll
#define INF 1e18+9
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define FIO ios_base::sync_with_stdio(false)
#define mod 1000000007
ll power(ll a,ll b,ll m)
{
    a%=m;
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=((ret%m)*(a%m))%m;
        a=((a%m)*(a%m))%m;
        b>>=1;
    }
    return ret;
}

int main()
{
    FIO;
    
    int te;
    cin >> te;

    while(te--){
        int n;
        cin >> n;

        string s,t;
        cin >> s >> t;

        vector < int > v;

        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                v.pb(i);
            }
        }

        vector < pair < int,int > > ans;
        int sig = 0;

        int count = 25;

        while(count--){
        for(int i=0;i<v.size();i++){
            if(s[v[i]] == t[v[i]]){
                continue;
            }

            for(int j=i+1;j<v.size();j++){
                if(t[v[j]] == t[v[i]]){
                    swap(s[v[i]],t[v[j]]);
                    ans.pb({v[i],v[j]});
                    break;
                }
            }

            if(s[v[i]] != t[v[i]]){
                swap(s[v[i]],t[v[i]]);
                ans.pb({v[i],v[i]});
            }

            for(int j=i+1;j<v.size();j++){
                if(t[v[j]] == t[v[i]]){
                    swap(s[v[i]],t[v[j]]);
                    ans.pb({v[i],v[j]});
                    break;
                }
            }
        }}

        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                sig = 1;
            }
        }

        if(sig || ans.size() > 2*n){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for(auto it : ans){
                cout << it.ff+1 << " " << it.ss+1 << endl;
            }
        }
    }   
    return 0;
}