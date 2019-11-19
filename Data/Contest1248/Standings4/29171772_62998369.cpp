#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
long long memo[N][3][3], mod = 1e9 + 7;
long long solve(int i, int node, int par){
    if(i == n)
        return 1;
    long long &ret = memo[i][node][par];
    if(ret != -1)
        return ret;
    ret = 0;
    if(par == 2 || node != par)
        ret = (solve(i + 1, 0, node) + solve(i + 1, 1, node))%mod;
    else
        ret = solve(i + 1, !node, node);
    ret %= mod;
    return ret;
}

int main(){
    cin >> n >> m;
    memset(memo, -1, sizeof memo);
    long long ans = solve(0, 2, 2);
    memset(memo, -1, sizeof memo);
    n = m;
    ans +=  solve(0, 2, 2);
    cout << (ans-2+mod) % mod;
}