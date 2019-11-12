#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mk make_pair
using namespace std;
const int N = 1123456;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
inline long long read () {
    char c = getchar();
    long long t = 0, f = 1;
    while (!isdigit(c)) f = (c == '-') ? -1 : 1, c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    return t * f;
}
int a[N];
void solve() {
    int n, m, i, j;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector <int> v;
    for(i = 0; i < n; i ++) {
        if(s[i] != t[i]) {
            v.pb(i);
        }
    }
    if(v.size() == 1 || v.size() > 2) {
        puts("No");
        return ;
    }
    if(v.size() == 2) {
        swap(s[v[0]], t[v[1]]);
        if(s == t) {
            puts("Yes");
            return ;
        }
        swap(s[v[0]], t[v[1]]);
        swap(s[v[1]], t[v[0]]);
        if(s == t) {
            puts("Yes");
            return ;
        }
        puts("No");
        return ;
    }
    puts("Yes");
}
main()
{
    int t = read();
    while(t -- > 0) {
        solve();
    }
}



