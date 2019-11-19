/*
  I_🧡🧡🧡_QMsh
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // gp_hash_table<int, int> table;

template <typename T> void smin(T &a, const T &b) { a = (a < b ? a : b); }
template <typename T> void smax(T &a, const T &b) { a = (a > b ? a : b); }

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

signed main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll n, k;
  cin >> n >> k;
  set <pair <int, int>> st;
  map <int, int> cnt;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (auto &i : cnt)
    st.insert(i);
  while (st.size() > 1 && k)
  {
    auto fr = *st.begin();
    auto nxt = *(++st.begin());
    auto ls = *(--st.end());
    auto prv = *(--(--st.end()));


    auto a = fr, b = nxt;

    if (fr.second > ls.second)
      fr = ls, nxt = prv;


    ll o = min(k / fr.second, (ll)abs(nxt.first - fr.first));
    if (!o)
      break;
    st.erase(fr);
    fr.first += (nxt.first > fr.first ? 1 : -1) * o;
    k -= o * fr.second;
    if (fr.first == nxt.first)
    {
      st.erase(nxt);
      fr.second += nxt.second;
    }
    st.insert(fr);
  }
  cout << st.rbegin()->first - st.begin()->first;

  return 0;
}