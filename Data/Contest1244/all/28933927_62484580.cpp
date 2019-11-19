#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define f first
#define s second

const int MAXN = 1e5 + 3;
const long long INF = 1e18 + 3;

long long t[MAXN];
set<pair<long long, long long> > q;

int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &t[i]);
    sort(t + 1, t + n + 1);
    long long cnt = 1;
    for (int i = 2; i <= n + 1; i++) {
        if (t[i] == t[i - 1]) {
            cnt++;
            continue;
        }
        q.insert({t[i - 1], cnt});
        cnt = 1;
    }
    pair<long long, long long> p, p2;
    long long roz, ile;
    auto iter = q.end();
    while (q.size() != 1 && k > 0LL) {
        p = *q.begin();
        iter = q.end();
        iter--;
        p2 = *iter;
        if (min(p.s, p2.s) > k) {
            k = 0LL;
            continue;
        }
        if (p2.s < p.s) {
            q.erase(iter);
            iter = q.end();
            iter--;
            p = *iter;
            roz = (p2.f - p.f) * p2.s;
            if (roz <= k) {
                k -= roz;
                q.erase(iter);
                q.insert({p.f, p.s + p2.s});
            }
            else {
                ile = k / p2.s;
                k -= ile * p2.s;
                q.insert({p2.f - ile, p2.s});
            }
        }
        else {
            q.erase(q.begin());
            p2 = *q.begin();
            roz = (p2.f - p.f) * p.s;
            if (roz <= k) {
                k -= roz;
                q.erase(q.begin());
                q.insert({p2.f, p.s + p2.s});
            }
            else {
                ile = k / p.s;
                k -= ile * p.s;
                q.insert({p.f + ile, p.s});
            }
        }
    }
    iter = q.end();
    iter--;
    printf("%lld", (*iter).f - (*q.begin()).f);
    return 0;
}

