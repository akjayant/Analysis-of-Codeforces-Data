#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector <vector <int> > all(3, vector <int> (n));
    for (int i = 0; i < n; i++)
        cin >> all[0][i];
    for (int i = 0; i < n; i++)
        cin >> all[1][i];
    for (int i = 0; i < n; i++)
        cin >> all[2][i];
    vector <vector <int> > graph(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if ((int)graph[i].size() > 2) {
            cout << "-1\n";
            return 0;
        }
    }
    int res = 1e18 + 7;
    vector <int> ans(n);
    for (int st = 0; st < n; st++) {
        if ((int)graph[st].size() != 1)
            continue;
        int a = st;
        int b = graph[st][0];
        for (int fir = 0; fir <= 2; fir++) {
            for (int sec = 0; sec <= 2; sec++) {
                for (int thir = 0; thir <= 2; thir++) {
                    if (fir != sec && fir != thir && sec != thir) {
                        //cout << "aaaaaaaaaaa\n";
                        vector <int> num(n);
                        num[a] = fir;
                        num[b] = sec;
                        int c;
                        if (graph[b][0] != st)
                            c = graph[b][0];
                        else
                            c = graph[b][1];
                        num[c] = thir;
                        int a1 = 0, b1 = 0, c1 = 0;
                        a1 += a;
                        b1 += b;
                        c1 += c;
                        for (int i = 3; i < n; i++) {
                            //cout << a << " " << b << " " << c << endl;
                            int d1;
                            if (graph[c1][0] != b1 || (int)graph[c1].size() == 1)
                                d1 = graph[c1][0];
                            else
                                d1 = graph[c1][1];
                            if (num[b1] != fir && num[c1] != fir)
                                num[d1] = fir;
                            else if (num[b1] != sec && num[c1] != sec)
                                num[d1] = sec;
                            else
                                num[d1] = thir;
                            a1 = b1;
                            b1 = c1;
                            c1 = d1;
                        }
                        int lol = 0;
                        for (int i = 0; i < n; i++)
                            lol += all[num[i]][i];
                        if (lol < res) {
                            res = lol;
                            ans.clear();
                            for (auto el : num)
                                ans.push_back(el);
                        }
                    }
                }
            }
        }
    }
    cout << res << "\n";
    for (auto el : ans)
        cout << el + 1 << " ";
    cout << "\n";
    return 0;
}
