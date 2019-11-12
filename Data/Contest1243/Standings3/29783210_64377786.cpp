#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 5;

char s[N], t[N];
vector<char> a, b;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        a.clear();
        b.clear();
        scanf("%d", &n);
        scanf("%s%s", s, t);

        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) { a.push_back(s[i]); b.push_back(t[i]); }
        }

        if(a.empty()) printf("Yes\n");
        else if(a.size() == 2 && b[1] == b[0] && a[0] == a[1]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
