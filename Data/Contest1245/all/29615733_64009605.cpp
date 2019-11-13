#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define pll pair<ll, ll>
#define pii pair<int, int>
#define mll map<ll, ll>
#define mii map<in, int>
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define p push
using namespace std;

ll a, b, c, n, dp[111][111][111];
string s, ans;

ll solve(int i, int A, int B) {
    if(i >= n) {
        return 0;
    }
    if(dp[i][A][B] != -1) return dp[i][A][B];
    ll res = 0;
    int C = c - (i - (a - A)  - (b - B));
    if(A > 0) {
        if(s[i] == 'S') {
            res = max(res, solve(i+1, A-1, B) + 1);
        }
        res = max(res, solve(i+1, A - 1, B));
    }
    if(C > 0) {
        if(s[i] == 'P') {
            res = max(res, solve(i+1, A, B) + 1);
        }
        res = max(res, solve(i+1, A, B));
    }
    if(B > 0) {
        if(s[i] == 'R') {
            res = max(res, solve(i+1, A, B - 1) + 1);
        }
        res = max(res, solve(i+1, A, B - 1));
    }
    return dp[i][A][B] = res;
}

void findPass(int i, int A, int B) {
    int C = c - (i - (a - A)  - (b - B));
    if(i >= n) return;
    if(A > 0) {
        if(s[i] == 'S') {
            if(solve(i, A, B) == 1 + solve(i+1, A-1, B)) {
                ans += 'R';
                findPass(i+1, A-1, B);
                return ;
            }
        }
        if(solve(i, A, B) ==solve(i+1, A-1, B)) {
            ans += 'R';
            findPass(i+1, A-1, B);
            return ;
        }
    }
    if(C > 0) {
        if(s[i] == 'P') {
            if(solve(i, A, B) == 1 + solve(i+1, A, B)) {
                ans += 'S';
                findPass(i+1, A, B);
                return ;
            }
        }
        if(solve(i, A, B) == solve(i+1, A, B)) {
            ans += 'S';
            findPass(i+1, A, B);
            return ;
        }
    }
    if(B > 0) {
        if(s[i] == 'R') {
            if(solve(i, A, B) == 1 + solve(i+1, A, B-1)) {
                ans += 'P';
                findPass(i+1, A, B-1);
                return ;
            }
        }
        if(solve(i, A, B) == solve(i+1, A, B-1)) {
            ans += 'P';
            findPass(i+1, A, B-1);
            return ;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>a>>b>>c>>s;
        for(int i = 0;i<=n;i++) {
            for(int j = 0;j<=a;j++) {
                for(int k = 0;k<=b;k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        ans = "";
        findPass(0, a, b);
        if(solve(0, a, b) >= (n + 1)/2) {
            cout<<"YES\n"<<ans<<'\n';
        } else {
            cout<<"NO\n";
        }
    }
}
//