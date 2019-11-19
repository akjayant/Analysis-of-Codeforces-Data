#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;
const int N = int(5e6) + 12, mod = int(1e9)  + 7;
ll x, parent[N], rnk[N];
vector<ll> f;
void go(ll x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            f.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }

    if (x != 1) {
        f.push_back(x);
    }
}
void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
}
 
int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap (a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>x;
    if(x == 1) {
        cout<<1;
        return 0;
    }
    go(x);
    int n = f.size();
    if(n == 1) {
        cout<<f[0];
        return 0;
    }
    int first = f[0];
    for(int i=1;i<=first;i++) {
        make_set(i);
    }
    for(int i=1;i<=first;i++) {
        for(int j=1;j<f.size();j++) {
            ll cur = f[j] + i;
            ll par = cur % first;
            if(!par)
                par += first;
            union_sets(i, par);
        }
    }
    ll ans = 0;
    for(int i=1;i<=first;i++) {
        if(parent[i] == i)
            ans++;
    }
    cout<<ans;
}
/*
 5 5 6
 1 2 3 4 5
 1 2 1 1
 2 3 1 3
 4 2 4 4
 2 5 1 4
 3 2 2 3
 3 2 3 3
 */
