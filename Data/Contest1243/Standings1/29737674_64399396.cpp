#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e6 + 10;
int T, n, a[maxn];
string s, t;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cin >> s >> t;
        vector<pii> vec;
        for (int i = 0; i < n; ++i) {
            if(s[i] != t[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if(s[i] == s[j] && s[j] != t[j]) {
                        vec.push_back({j+1, i+1});
                        swap(s[j], t[i]);
                        break;
                    }
                    if(s[i] == t[j] && s[j] != t[j]) {
                        vec.push_back(make_pair(j+1, j+1));
                        swap(s[j], t[j]);
                        vec.push_back(make_pair(j+1, i+1));
                        swap(t[i], s[j]);
                        break;
                    }
                }
            }
        }

        if(s != t) puts("No");
        else {
            puts("Yes");
            printf("%d\n", vec.size());
            for (auto cur: vec) printf("%d %d\n", cur.first, cur.second);
        }
    }
    return 0;
}