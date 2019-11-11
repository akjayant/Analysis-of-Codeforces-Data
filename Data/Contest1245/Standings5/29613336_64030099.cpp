#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <math.h>
#include <cmath>
#include <map>

#define ll long long
#define rt return
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pii pair<int, int>
using namespace std;

const int MAX_SIZE = 3 * 1e5, INF = 2 * 1e9;
const long long SuperINF = 1e14, MOD = 1e9 + 7;
const double eps = 0.5, PI = 3.141592653589793;

void files() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<ll> arr;
string s;
ll dp[MAX_SIZE][2];


int main() {
    std::ios::sync_with_stdio(0);
    //files();
    cin >> s;
    ll cnt = 0;
    char c = 'n';
    map<char, string> info;
    info['m'] = "nn";
    info['w'] = "uu";
    info['n'] = "n";
    info['u'] = "u";
    
    
    for (auto x : s) {
        if (x == 'm' || x == 'w') {
            cout << 0;
            return 0;
        }
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (!(s[i] == 'u' || s[i] == 'n' || s[i] == 'w' || s[i] == 'm')) {
            if (cnt != 0) {
                arr.push_back(cnt);
                cnt = 0;
            }
            continue;
        }
        
        string st = info[s[i]];
        if (st[0] == c)
            cnt += st.size();
        else {
            if (cnt != 0) {
                arr.push_back(cnt);
            }
            
            if (st[0] == 'u' || st[0] == 'n') {
                cnt = st.size();
                c = st[0];
            }
        }
    }
    
    
    if (cnt != 0)
        arr.push_back(cnt);
    
    dp[0][0] = 1;
    dp[1][0] = 1;
    
    for (int i = 2; i < MAX_SIZE; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
    }
    
    ll ans = 1;
    
    for (auto x : arr) {
        ans *= (dp[x][0] + dp[x][1]) % MOD;
        ans %= MOD;
    }
    
    cout << ans;
    rt 0;
}


