#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i <= k; i++)
#define ROF(i, j, k) for(int i = j; i >= k; i--)
#define PB push_back
#define MEM(n, val) memset((n), val, sizeof(n))
#define F first
#define S second
#define MP make_pair
#define LL long long
#define MOD 1000000007
#define INF 1000000000
#define MX 300010
#define pi 2.0*acos(0.0)

typedef pair<int, int> PII;

int n, m;
vector<int> adjl[100010];
set<int> taken, not_taken;
deque<int> dq;

int main()  {
//    freopen("in.txt", "r", stdin);
//    freopen("output0.txt", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, m)   {
        int u, v;
        cin >> u >> v;
        adjl[u].PB(v);
        adjl[v].PB(u);
    }
    FOR(i, 1, n)   {
        adjl[i].PB(0);
        adjl[i].PB(n + 1);
        sort(adjl[i].begin(), adjl[i].end());
        not_taken.insert(i);
    }

    int tt = 1;
    FOR(i, 1, n)   {
        if(adjl[i].size() != (n + 1))    {
//            if(not_taken.find(i) == not_taken.end())    {
//                continue;
//            }
            tt = i;
            break;
        }
    }

    dq.push_back(tt);
    not_taken.erase(tt);
//    cout << "tt : " << tt << "\n";

    int cnt = 0;

    while(!not_taken.empty()) {
        int u = dq.front();
        dq.pop_front();
//        cout << u << " : ";

        for(int i = 1; i < (int)adjl[u].size(); i++)   {
            int v = adjl[u][i];
            int pv = adjl[u][i - 1];
//            cout << "(" << pv << "," << v << ") ";
            if(pv == v - 1)    {
                continue;
            }
            while(!not_taken.empty()) {
                auto it = not_taken.upper_bound(pv);
                if(it == not_taken.end())    {
                    break;
                }
                int val = (*it);
//                cout << val << " ";
                if(val >= v)    {
                    break;
                }

                dq.push_back(val);
                not_taken.erase(val);
            }
        }
//        cout << "\n";
        if(dq.empty())    {
            if(not_taken.empty())    {
                continue;
            }
            int yo = (*(not_taken.begin()));
            dq.push_back(yo);
            not_taken.erase(yo);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
