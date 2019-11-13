/*input

*/
/**
    Author: Kristopher Paul
    Date Created: 06-11-2019
    Contest Name:
                _/    _/   _/_/_/_/   _/   _/_/_/_/
               _/  _/     _/    _/   _/   _/
              _/_/       _/_/_/_/   _/   _/_/_/_/
             _/  _/     _/  _/     _/         _/
            _/    _/   _/    _/   _/   _/_/_/_/
**/
#include<bits/stdc++.h>
#include<stdio.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int ll
#define pb push_back
#define INF 1e18
#define MOD 1000000007
//#define MOD 998244353
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define umap unordered_map
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define out(x) cout << #x << " is " << x << endl
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // set
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // multiset

int ModExp(int x,int y,int m){
    int res = 1;
    x = x % m;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % m;

        y = y>>1;
        x = (x*x) % m;
    }
    return res;
}

vector<pii> mo;
string s,t;
void swap(int i,int j){
    char a = s[i];
    s[i] = t[j];
    t[j] = a;
    mo.pb({i+1,j+1});
}

void solve(){
    mo.clear();
    int n;
    cin >> n;
    cin >> s >> t;
    umap<char,vi> a;
    umap<char,vi> b;
    FORD(i,n-1,0){
        a[s[i]].pb(i);
    }
    FORD(i,n-1,0){
        b[t[i]].pb(i);
    }
    FOR(i,'a','z'+1){
        int c = a[i].size()+b[i].size();
        if(c % 2 == 1){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    FOR(i,0,n){
        if(s[i] == t[i]){
            continue;
        }
        int s1 = 0,s2 = 0;
        FOR(j,i+1,n){
            if(s[j] == s[i]){
                s1 = j;
            }else if(s[j] == t[i]){
                s2 = j;
            }
        }
        int t1 = 0,t2 = 0;
        FOR(j,i+1,n){
            if(t[j] == t[i]){
                t1 = j;
            }else if(t[j] == s[i]){
                t2 = j;
            }
        }
        if(s1 != 0){
            swap(s1,i);
        }else if(t1 != 0){
            swap(i,t1);
        }else{
            swap(s2,t2);
            swap(s2,i);
        }
    }
    cout << mo.size() << endl;
    FOR(i,0,mo.size()){
        cout << mo[i].first << " " << mo[i].second << endl;
    }
}

signed main(){
    FastIO;
    int t = 1;
    cin >> t;
    WL(t){
        solve();
    }
}
