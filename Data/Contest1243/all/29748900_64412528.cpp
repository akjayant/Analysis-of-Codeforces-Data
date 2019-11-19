#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

set<int> T1, T2;
vector<int> ANS, G[N];
int tmp;
void bfs(int s) {
    tmp = 1;
    T1.erase(s);
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int top = que.front();
        que.pop();
        for(int &v : G[top]) {
            if(!T1.count(v))
                continue;
            T1.erase(v);
            T2.insert(v);
        }
        for(auto it : T1) {
            ++tmp;
            que.push(it);
        }
        T1.swap(T2);
        T2.clear();
    }
    ANS.push_back(tmp);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        T1.insert(i);
    if(m < n - 1) {
        printf("0\n");
        return 0;
    }
    while(m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(T1.count(i))
            bfs(i);
    cout << ANS.size() - 1 << endl;
    return 0;
}