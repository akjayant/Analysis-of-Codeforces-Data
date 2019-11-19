#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> E;
struct cmp{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return E[a.first][a.second] > E[b.first][b.second];
    }
};

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> P(n);
    for(auto& p : P)
        cin >> p.first >> p.second;
    
    vector<long long> C(n), K(n);
    for(auto& c : C)
        cin >> c;
    for(auto& k : K)
        cin >> k;
    
    E = vector<vector<long long>>(n+1, vector<long long>(n+1));
    for(auto i = 1; i <= n; ++i)
        E[0][i] = E[i][0] = C[i-1];
    
    for(auto i = 1; i <= n; ++i) {
        for(auto j = 1; j <= n; ++j) {
            E[i][j] = (K[i-1] + K[j-1]) * (abs(P[i-1].first - P[j-1].first) + abs(P[i-1].second - P[j-1].second));
        }
    }

    long long min_cost = 0;
    vector<int> power;
    vector<pair<int, int>> connect;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<bool> visited(n+1);
    visited[0] = true;
    for(auto i = 1; i <= n; ++i)
        pq.push({0, i});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if(visited[cur.second])
            continue;
        visited[cur.second] = true;
        if(cur.first == 0) {
            power.push_back(cur.second);
            min_cost += E[cur.first][cur.second];
        }
        else {
            connect.push_back(cur);
            min_cost += E[cur.first][cur.second];
        }
        for(auto i = 1; i <= n; ++i)
            if(!visited[i])
                pq.push({cur.second, i});
    }

    cout << min_cost << endl;
    cout << power.size() << endl;
    for(auto i : power)
        cout << i << ' ';
    cout << endl;
    cout << connect.size() << endl;
    for(auto& p : connect)
        cout << p.first << " " << p.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}