#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;
 
/////////////////////////////////////////////
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
////////////////////////////////


 
#define int long long
const int mod = 1e9 + 7;

void solve(){

    int n;
    cin>>n;
    string s , t;
    cin>>s>>t;

    int fs[26] , ft[26];
    memset(fs , 0 , sizeof fs);
    memset(ft , 0 , sizeof ft);

    for(char c : s)
        fs[c-'a']++;
    for(char c : t)
        fs[c-'a']++;

    for(int i = 0 ; i < 26 ; ++i){

        if(fs[i]%2!=0){

            cout<<"No\n";
            return ;
        }
    }

    vector<pair<int,int>> moves;

    for(int i = 0 ; i < n ; ++i){

        if(s[i]!=t[i]){

            bool ok = false;
            int id = -1;
            for(int j = i+1 ; j < n; ++j){

                if(s[j]==s[i] && s[j]!=t[j]){

                    ok = true;
                    id = j;
                    break;
                }
            }

            if(ok){

                swap(t[i] , s[id]);
                moves.pb({id , i});
                continue;
            }
            else {

                ok = false;
                id = -1;

                for(int j = i+1 ; j < n;  ++j){

                    if(s[i]==t[j] && s[j]!=t[j]){

                        ok = true;
                        id = j;
                        break;
                    }
                }

                if(ok){

                    int j = id;
                    moves.pb({j , j});
                    moves.pb({j , i});
                    swap(s[j] , t[j]);
                    swap(s[j] , t[i]);
                    // if(s[j]!=t[j]){

                    //     moves.pb({j , j});
                    //     swap(s[j] , t[j]);
                    // }
                }

                continue;
            }
        }
    }


    cout<<"Yes\n";
    cout<<moves.size()<<endl;

    for(auto it : moves)
        cout<<it.ff+1<<" "<<it.ss+1<<endl;

}
signed main(){
 
    fast;
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}