#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
#define cases(t) for (int cas = 1; cas <= int(t); ++cas)
typedef long long ll;
typedef double db;
using namespace std;

#ifdef NO_ONLINE_JUDGE
#define LOG(args...) do { cout << #args << " -> "; err(args); } while (0)
void err() { cout << endl; }
template<typename T, typename... Args> void err(T a, Args... args) { cout << a << ' '; err(args...); }
#else
#define LOG(...)
#endif

const int N = 100005;
const ll mod = 1e9 + 7;

ll f[N];
char s[N];
vector<int> m, w;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int cntm = 0, cntw = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'm' || s[i] == 'w')	return 0 * puts("0");
        if (s[i] == 'n') {
            if (i > 0 && s[i - 1] != s[i])	{
                if (cntm > 0)	m.push_back(cntm);
                cntm = 1;
            } else cntm++;
        } else if (s[i] == 'u') {
            if (i > 0 && s[i - 1] != s[i])	{
                if (cntw > 0)	w.push_back(cntw);
                cntw = 1;
            } else cntw++;
        } else {
            if (cntm > 0)	m.push_back(cntm), cntm = 0;
            if (cntw > 0)	w.push_back(cntw), cntw = 0;
        }
    }
    if (cntm > 0)	m.push_back(cntm);
    if (cntw > 0)	w.push_back(cntw);
    ll ans = 1;
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; ++i)	f[i] = (f[i - 1] + f[i - 2]) % mod;
    for (auto v : m)	ans = (ans * f[v]) % mod;
    for (auto v : w)	ans = (ans * f[v]) % mod;
    printf("%lld\n", ans);
    return 0;
}