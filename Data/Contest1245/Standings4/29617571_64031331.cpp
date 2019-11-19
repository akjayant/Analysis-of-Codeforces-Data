// "Copyright 2019 Artem Yena"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

const int INF = 2147483647;

long long n, t, head, M[2000][2000], X[2000], Y[2000], C[2000];
long long ans, mi, K[2000], vis[2000], price[2000], links[2000];
vector <int> stations;
vector<pair<int, int> > pairs;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> X[i] >> Y[i];
    }
    for (int i = 0; i < n; ++i) cin >> C[i];
    for (int i = 0; i < n; ++i) cin >> K[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int d = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
            M[i][j] = d * (K[j] + K[i]);
        }
    for (int i = 0; i < n; ++i) vis[i] = 0;
    for (int i = 0; i < n; ++i) price[i] = C[i];
    for (int i = 0; i < n; ++i) links[i] = -1;
    t = 1;
    while(t)
    {
        mi = INF;
        head = -1;
        t = 0;
        for (int i = 0; i < n; ++i)
        {
            if (price[i] < mi && !vis[i])
            {
                mi = price[i];
                head = i;
                t = 1;
            }
        }
        if (!t) break;
        vis[head] = 1;
        if (links[head] == -1)
        {
            stations.push_back(head);
        }
        else
        {
            pairs.push_back(make_pair(head, links[head]));
        }
        for (int j = 0; j < n; ++j)
        {
            if (M[head][j] < price[j] && !vis[j])
            {
                price[j] = M[head][j];
                links[j] = head;
            }
        }
    }
    ans = 0;
    for (int i = 0; i < n; ++i) ans += price[i];
    cout << ans << '\n';
    cout << stations.size() << '\n';
    for (int i = 0; i < stations.size(); ++i)
    {
        cout << stations[i] + 1 << ' ';
    }
    cout << '\n' << pairs.size() << '\n';
    for (int i = 0; i < pairs.size(); ++i)
    {
        cout << pairs[i].first + 1<< ' ' << pairs[i].second + 1<< '\n';
    }

}
