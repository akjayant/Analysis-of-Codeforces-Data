#include<bits/stdc++.h>
using namespace std;
 
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i)
 
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int mod = 1e9+7;
const int inf = 2e18+5;
const int nax = 101010;
//
int dp[nax];


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("fin.txt", "r", stdin);
        freopen("fout.txt", "w", stdout);
    #endif
    //

    string s; cin >> s;
    int n = s.length();

    loop(i, 0, n){
        if(s[i] == 'w' || s[i] == 'm'){
            cout << 0;
            return 0;
        }
    }

    dp[1] = 1;
    dp[2] = 2;

    loop(i, 3, nax){
        dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= mod;
    }

    vector<int> cnt;

    int curr = 0;
    loop(i, 0, n){
        if(s[i] == 'u'){
            curr++;
        }else{
            if(curr != 0) cnt.pb(curr);
            curr = 0;
        }
    }
    if(curr != 0) cnt.pb(curr);

    curr = 0;
    loop(i, 0, n){
        if(s[i] == 'n'){
            curr++;
        }else{
            if(curr != 0) cnt.pb(curr);
            curr = 0;
        }
    }
    if(curr != 0) cnt.pb(curr);

    int res = 1;
    for(auto x : cnt){
        res *= dp[x];
        res %= mod;
    }

    cout << res;



    return 0;
}