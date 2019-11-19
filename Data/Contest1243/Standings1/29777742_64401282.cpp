//#include <bits/stdc++.h>
//
//using namespace std;
//#define taskname "cf1243"
//typedef pair < int, int > ii;
//
//int T, n;
//string s, t;
//bool visited[55];
//vector < int > pos;
//
//int main()
//{
//    #ifdef duyenn
//        freopen (taskname".inp", "r", stdin);
//        freopen (taskname".out", "w", stdout);
//    #endif // duyenn
//    ios_base::sync_with_stdio(false);
//    cin.tie(); cout.tie();
//    for (cin >> T; T--;)
//    {
//        cin >> n >> s >> t;
//        if (s == t)
//        {
//            cout << "YES\n";
//            continue;
//        }
//        pos.clear();
//        for (int i = 0; i < n; i++)
//            if (s[i] != t[i])
//                pos.push_back(i);
//        if (pos.size() == 1)
//        {
//            cout << "NO\n";
//            continue;
//        }
//        memset(visited, 0, sizeof(visited));
//        vector < ii > res;
//        bool ok = true;
//        while (2)
//        {
//            if (pos.size() == 1)
//            {
//                ok = false;
//                break;
//            }
//            bool ok2 = false;
//            for (int i = 0; i < pos.size(); i++)
//            {
//                int u = pos[i];
//                if (visited[u] == false)
//                {
//                    for (int j = i + 1; j < pos.size(); j++)
//                    {
//                        int v = pos[j];
//                        if (visited[j] == false)
//                        {
//                            if ((s[u] == s[v] && t[u] == t[v]))
//                            {
//                                ok2 = visited[u] = visited[v] = true;
//                                res.push_back(ii(u, v));
//                                goto line;
//                            }
//                        }
//                    }
//                }
//            }
//            line:;
//            if (!ok2)
//            {
//                ok = false;
//                break;
//            }
//        }
//        if (!ok)
//            cout << "NO\n";
//        else
//        {
//            cout << res.size() << '\n';
//            for (auto x: res)
//                cout << x.first << " " << x.second << '\n';
//        }
//    }
//}
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
#define taskname "cf1243"

ll n;
vector < ll > gcd;

bool isPrime(ll x)
{
    if (x < 2)
        return false;
    for (ll i = 2; i * i <= x; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n;
    if (isPrime(n))
        return cout << n, 0;
    ll N = n;
    for (ll i = 2; i * i <= n; i++)
        if (N % i == 0)
        {
            gcd.push_back(i);
            while (N % i == 0)
                N /= i;
        }
    if (N != 1)
        gcd.push_back(N);
    if (gcd.size() == 1)
        return cout << gcd[0], 0;
    sort (gcd.begin(), gcd.end());
    if (gcd[0] == 2 && gcd[1] == 3)
        return cout << 1, 0;
    cout << 1;
}

