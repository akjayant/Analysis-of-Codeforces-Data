#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<stack>
#include<algorithm>
#include<string>
#include<string.h>
#include<assert.h>
#include<iomanip>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const int N = 32;
const int LOG = 30;

int L, R;
ll dp[N][2][2];

ll rec(int bit, int fa, int fb, int val){
    if(bit == -1)return 1;
    if(dp[bit][fa][fb] != -1)return dp[bit][fa][fb];
    ll res = 0;

    int mxa = 2, mxb = 2;
    if(fa == 1){
        if(val & L)mxa = 2;
        else mxa = 1;
    }
    if(fb == 1){
        if(val & R)mxb = 2;
        else mxb = 1;
    }
    for(int i = 0; i < mxa; ++i){
        for(int j = 0; j < mxb; ++j){
            if(i + j == (i ^ j))
                res += rec(bit - 1, (fa == 1) && (i + 1 == mxa), (fb == 1) && (j + 1 == mxb), val / 2);
        }
    }
    // cout << bit << " " << fa << " " << fb << " " << res << endl;
    return dp[bit][fa][fb] = res;

    // if(fa == 1){ 
    //     if(fb == 1){ // restricted
    //         if(val & L){
    //             if(val & R){ // boleh nyala 2-2nya
    //                 res += rec(bit - 1, fa, 0, val / 2);
    //                 res += rec(bit - 1, 0, fb, val / 2);
    //                 res += rec(bit - 1, 0, 0, val / 2);
    //             }else{ // boleh nyala a
    //                 res += rec(bit - 1, fa, fb, val / 2);
    //                 res += rec(bit - 1, 0, fb, val / 2);
    //             }
    //         }else{
    //             if(val & R){ // boleh nyala b
    //                 res += rec(bit - 1, fa, fb, val / 2);
    //                 res += rec(bit - 1, fa, 0, val / 2);
    //             }else{
    //                 res += rec(bit - 1, fa, fb, val / 2);
    //             }
    //         }
    //     }else{ // b bebas
    //         if(val & L){ // a restricted
    //             res += rec(bit - 1, fa, 0, val / 2); // a nyala -> b mati
    //             res += rec(bit - 1, 0, 0, val / 2) * 2; // a mati -> b boleh mati/nyala
    //         }else{ // a harus mati
    //             res += rec(bit - 1, 0, 0, val / 2) * 2; // a mati -> b boleh mati/nyala
    //         }
    //     }
    // }else{
    //     if(fb == 1){ // b restricted
    //         if(val & R){
    //             res += rec(bit - 1, 0, fb, val / 2);
    //             res += rec(bit - 1, 0, 0, val / 2) * 2;
    //         }else{
    //             res += rec(bit - 1, 0, 0, val / 2) * 2;
    //         }
    //     }else{
    //         res = rec(bit - 1, fa, fb, val / 2) * 3;
    //     }
    // }

    
}

ll solve(int l, int r){
    if(r < 0 || l < 0)return 0;
    memset(dp, -1, sizeof dp);
    L = l, R = r;
    // ll bf = 0;
    // for(int i = 0; i <= l; ++i){
    //     for(int j = 0; j <= r; ++j){
    //         if(i + j == (i ^ j))bf++;
    //     }
    // }
    // cout << "Solve " << L << " " << R << " = " << rec(LOG, 1, 1, 1<<LOG) << " " << bf << endl;
    return rec(LOG, 1, 1, 1 << LOG);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        ll ans = solve(r, r) - solve(r, l - 1) - solve(l - 1, r) + solve(l - 1, l - 1);
        cout << ans << endl;
    }
}