#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int f(const vi &a) {
    int n = a.size();
    deque<int> dq(a.begin(), a.end());

    int sum = 0, mn = n;
    for (int i = 0; i < n; i++) {
        sum += dq[i];
        mn = min(mn, sum);
    }
    if (sum != 0)
        return 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        dq.push_front(dq.back());
        dq.pop_back();
        mn = min(dq.front(), mn + dq.front());
        if (mn == 0)
            ret++;
    }
    return ret;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vi a(n);
    for (int i = 0; i < n; i++)
        a[i] = s[i] == '(' ? 1 : -1;
    int mx = -1, l, r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(a[i], a[j]);
            if (f(a) > mx) {
                mx = f(a);
                l = i, r = j;
            }
            swap(a[i], a[j]);
        }
    }
    cout << mx << endl << l + 1 << " " << r + 1 << endl;
    return 0;
}