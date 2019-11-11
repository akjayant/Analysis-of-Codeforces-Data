#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second
#define pb push_back
#define len(x) (int) x.size();
#define all(a) a.begin(), a.end()

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a) for (int i = 0; i < a.size(); ++i) cin >> a[i];
#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;
#define printvp(x, text) cout << text << " =\n"; for (auto e : x) cout << e.first << ' ' << e.second << endl; cout << endl;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    fast_io;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
}
