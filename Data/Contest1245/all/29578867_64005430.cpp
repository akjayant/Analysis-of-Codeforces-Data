#include <bits/stdc++.h>
using namespace std;

char s[111], tkkn[111];

int main() {
        ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int test; cin >> test;
        while(test--) {
                memset(tkkn, 0, sizeof tkkn);
                int n, a, b, c, cnt = 0; cin >> n >> a >> b >> c;
                string str; cin >> str;
                int idx = 0;
                for(auto ch: str) {
                        if(ch == 'R' && b) {
                                --b;
                                ++cnt;
                                tkkn[idx] = 1;
                                s[idx] = 'P';

                        } else if(ch == 'P' && c) {
                                --c;
                                ++cnt;
                                tkkn[idx] = 1;
                                s[idx] = 'S';
                        } else if(ch == 'S' && a) {
                                --a;
                                ++cnt;
                                tkkn[idx] = 1;
                                s[idx] = 'R';
                        }
                        ++idx;
                }
                if(cnt >= (n + 1) / 2) {
                        cout << "YES" << endl;
                        for(int i = 0; i < n; i++) {
                                if(tkkn[i]) cout << s[i];
                                else {
                                        if(a) {
                                                cout << 'R';
                                                --a;
                                        } else if(b) {
                                                cout << 'P';
                                                --b;
                                        } else if(c) {
                                                cout << 'S';
                                                --c;
                                        }
                                }
                        }
                        cout << endl;
                } else cout << "NO" << endl;
        }
}