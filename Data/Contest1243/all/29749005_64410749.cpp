#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 15;

ll n;
vector<int> fac;

void getfac(ll x) {
    for (int i = 2; i <= int(x / 2); ++i) {
        if (x % i == 0) {
            fac.push_back(i);
        }
    }
}

int f[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) {
        f[i] = i;
    }
}

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        f[x] = y;
    }
}

void fac2(ll x) {
    for (int i = 2; 1LL * i * i <= x; i++) {
        if (x % i == 0) fac.push_back(i);
        while (x % i == 0) x = x / i;
    }
    if(x != 1){
        fac.push_back(x);
    }
}

bool isprime(ll x){
    for (int i = 2; 1LL * i * i <= x; ++i) {
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int check(int n) {
    if (fac.empty()) {
        return n;
    }
    if (fac.size() == 1 && isprime(fac[0])) {
        return fac[0];
    }
    return 1;
}

int main() {
    cin >> n;
    if(isprime(n)){
        cout << n;
        return 0;
    }
    fac2(n);
    if(fac.size() == 1){
        cout << fac[0];
        return 0;
    }
    cout << 1;
    return 0;
    for (int i = 1; i <= 90; ++i) {
        fac.clear(), init();
        getfac(i);

        for (int j = 1; j <= i; ++j) {
            for (auto e:fac) {
                if (j + e > i) {
                    break;
                }
                merge(j, j + e);
            }
        }
        int cnt = 0;
        for (int j = 1; j <= i; ++j) {
            if (f[j] == j) {
                ++cnt;
            }
        }
        cout << "i = " << i << " " << cnt << '\n';
        for (auto e:fac) {
            cout << e << ',';
        }
        cout << endl;
        if (check(i) != cnt) {
            break;
        }
    }
    return 0;
}
//1,2,3,2,5,1,7,2,3,1,11

