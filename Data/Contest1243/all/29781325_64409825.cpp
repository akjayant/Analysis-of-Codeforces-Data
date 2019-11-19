#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < _n; ++i)
#define FJ(_n) for(int j = 0; j < _n; ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

set<pair<int, int>> s;
unordered_set<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int n, m;
    cin >> n >> m;
    FI(m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        s.insert(mp(min(x, y), max(x, y)));
    }
    FI(n)
        v.insert(i);

    int add = -1;
    queue<int> q;
    while (!v.empty())
    {
        add++;
        q.push(*v.begin());
        v.erase(v.begin());
        while (!q.empty())
        {
            int vs = q.front();
            q.pop();
            for (auto it = v.begin(); it != v.end();)
            {
                if (s.find(mp(min(vs, *it), max(vs, *it))) == s.end())
                {
                    q.push(*it);
                    it = v.erase(it);
                }
                else
                    it++;
            }
        }
    }

    cout << add;

    return 0;
}
