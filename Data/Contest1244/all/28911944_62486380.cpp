#include <bits/stdc++.h>

#define pb push_back
#define debug(x) cout << #x << "  :  " << x


using namespace std;

vector <vector <long long> > lst;
vector <long long> cost1, cost2, cost3;
vector <long long> tps1, tps2;

void dfs1 (long long v, long long p = -1) {
    for (auto& i : lst[v]) {
        if (i == p) continue;
        dfs1(i, v);
    }
    tps1.pb(v);
}
void dfs2 (long long v, long long p = -1) {
    for (auto& i : lst[v]) {
        if (i == p) continue;
        dfs2(i, v);
    }
    tps2.pb(v);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;

    lst.resize(n);
    cost1.resize(n);
    cost2.resize(n);
    cost3.resize(n);
    for (long long i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        cost1[i] = a;
    }
    for (long long i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        cost2[i] = a;
    }
    for (long long i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        cost3[i] = a;
    }
    for (long long i = 0; i < n - 1; ++i) {
        long long a, b;
        cin >> a >> b;
        a--, b--;
        lst[a].pb(b);
        lst[b].pb(a);
    }
    long long listya = 0, cnt = 0;
    for (long long i = 0; i < n; ++i) {
        if (lst[i].size() == 1)
            listya++;
        else if (lst[i].size() == 2)
            cnt++;
    }
    if (listya + cnt == n) {
        int cur = 0;
        for (long long i = 0; i < n; ++i) {
            if (lst[i].size() == 1) {
                if (cur == 0)
                    dfs1(i), cur++;
                else
                    dfs2(i);
            }
        }
        reverse(tps1.begin(), tps1.end());
        long long mx1 = 1e18;
        vector <long long> ans1;
        for (long long i = 1; i <= 3; ++i) {
            for (long long j = 1; j <= 3; ++j) {
                if (i == j) continue;
                vector <long long> now(n, 0);
                now[tps1[0]] = i;
                now[tps1[1]] = j;
                for (long long k = 2; k < n; ++k) {
                    now[tps1[k]] = 6 - now[tps1[k-1]] - now[tps1[k-2]];
                }
                long long cost = 0;
                for (long long k = 0; k < n; ++k) {
                    if (now[tps1[k]] == 1)
                        cost += cost1[tps1[k]];
                    else if (now[tps1[k]] == 2)
                        cost += cost2[tps1[k]];
                    else
                        cost += cost3[tps1[k]];
                }
                if (cost < mx1) {
                    mx1 = cost;
                    ans1 = now;
                }
            }
        }

        reverse(tps2.begin(), tps2.end());
        long long mx2 = 1e18;
        vector <long long> ans2;
        for (long long i = 1; i <= 3; ++i) {
            for (long long j = 1; j <= 3; ++j) {
                if (i == j) continue;
                vector <long long> now(n, 0);
                now[tps2[0]] = i;
                now[tps2[1]] = j;
                for (long long k = 2; k < n; ++k) {
                    now[tps2[k]] = 6 - now[tps2[k-1]] - now[tps2[k-2]];
                }
                long long cost = 0;
                for (long long k = 0; k < n; ++k) {
                    if (now[tps2[k]] == 1)
                        cost += cost1[tps2[k]];
                    else if (now[tps2[k]] == 2)
                        cost += cost2[tps2[k]];
                    else
                        cost += cost3[tps2[k]];
                }
                if (cost < mx2) {
                    mx2 = cost;
                    ans2 = now;
                }
            }
        }
        if (mx1 < mx2) {
            cout << mx1 << endl;
            for (auto& el : ans1)
                cout << el << ' ';
        }
        else {
            cout << mx2 << endl;
            for (auto& el : ans2)
                cout << el << ' ';
        }
    }
    else {
        cout << -1;
    }
    return 0;
}