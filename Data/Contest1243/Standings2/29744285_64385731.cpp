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
    map <int, int> mp;
    for(i = 0; i < n; i ++) {
        mp[s[i]] ++;
        mp[t[i]] ++;
    }
    for(i = 'a'; i <= 'z'; i ++) {
        if(mp[i] % 2 != 0) {
            puts("No");
            return ;
        }
    }
    vector <pair <int, int> > v;
    for(i = 0; i < n; i ++) {
        if(s[i] != t[i]) {
            for(int j = i + 1; j < n; j ++) {
                if(t[i] == t[j]) {
                    v.pb(mk(i, j));
                    swap(s[i], t[j]);
                    break;
                }
            }
            if(s[i] != t[i]) {
                for(int j = i + 1; j < n; j ++) {
                    if(t[i] == s[j]) {
                        v.pb(mk(j, j));
                        swap(s[j], t[j]);
                        v.pb(mk(i, j));
                        swap(s[i], t[j]);
                        break;
                    }
                }
            }
        }
    }
    puts("Yes");
    cout << v.size() << endl;
    for(i = 0; i < v.size(); i ++) {
        cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
    }
}
main()
{
    int t = read();
    while(t -- > 0) {
        solve();
    }
}



