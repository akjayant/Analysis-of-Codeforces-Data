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

int maps[10][10];
int num[10][10];
int val[105];
int jump[105];

double dp[105][2];
bool vis[105][2];

// last = 1 -> ladder last move
double rec(int idx, int last){
    if(idx == 100)return 0;
    if(vis[idx][last])return dp[idx][last];
    double ladder = 1e9 + 5;
    if(last == 0 && val[idx] != 0){ // can choose ladder
        ladder = rec(jump[idx], 1);
    }
    double roll = 6;
    int cnt = 0;
    for(int i = 1; i <= 6; ++i){ // roll dice
        int nx = idx + i;
        if(nx <= 100)roll += rec(nx, 0);
        else{
            cnt++;
        }
    }
    if(cnt == 0) roll /= 6;
    else{
        roll = roll / (6 - cnt);
    }
    double res = min(roll, ladder);
    vis[idx][last] = true;
    // cout << idx << " " << last << " -> " << res << " " << cnt << endl;
    return dp[idx][last] = res;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> maps[i][j];
        }
    }

    int cnt = 1;
    for(int i = 9; i >= 0; --i){
        if(i & 1){
            for(int j = 0; j < 10; ++j){
                val[cnt] = maps[i][j];
                num[i][j] = cnt++;
            }
        }else{
            for(int j = 9; j >= 0; --j){
                val[cnt] = maps[i][j];
                num[i][j] = cnt++;
            }
        }
    }

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            if(maps[i][j] == 0)continue;
            jump[num[i][j]] = num[i - maps[i][j]][j];
        }
    }

    cout << rec(1, 0) << endl;

}