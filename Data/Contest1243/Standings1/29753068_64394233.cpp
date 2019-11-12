#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_map>
#include <tuple>
#include <cmath>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <cassert>
#include <numeric>
using namespace std;
#define kekek ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main() {
    kekek;
    
    int sz = 'z' - 'a' + 1;
    int k;
    cin >> k;
    while (k--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector<set<int>> s1(sz), t1(sz);
        vector<int> kek('z' - 'a' + 1, 0);
        for (int i = 0; i < n; i++) {
            kek[s[i] - 'a']++;
            kek[t[i] - 'a']++;
            s1[s[i] - 'a'].insert(i);
            t1[t[i] - 'a'].insert(i);
        }

        bool f = true;
        for (int i = 0; i < 'z' - 'a' + 1; i++) {
            if (kek[i] % 2 != 0) {
                f = false;
                break;
            }
        }

        if (f) {
            cout << "Yes\n";
            
            vector<pair<int, int>> ans;
            for (int i = 0; i < n; i++) {
                s1[s[i] - 'a'].erase(i);
                t1[t[i] - 'a'].erase(i);

                if (t[i] == s[i]) continue;
                if (s1[s[i] - 'a'].empty()) {
                    int post = *t1[s[i] - 'a'].begin();
                    int pos = i + 1;
                    s1[s[i + 1] - 'a'].erase(i + 1);
                    t1[s[i] - 'a'].erase(t1[s[i] - 'a'].begin());
                    swap(s[pos], t[post]);
                    //cout << pos + 1 << " " << post + 1 << '\n';
                    ans.push_back({ pos, post });
                    t1[t[post] - 'a'].insert(post);

                    swap(s[pos], t[i]);
                    //cout << pos + 1 << " " << i + 1 << '\n';
                    ans.push_back({ pos, i });
                    s1[s[i + 1] - 'a'].insert(i + 1);
                }
                else {
                    int pos = *s1[s[i] - 'a'].begin();
                    s1[s[i] - 'a'].erase(s1[s[i] - 'a'].begin());
                    swap(s[pos], t[i]);
                    
                    //cout << pos + 1 << " " << i + 1 << '\n';
                    ans.push_back({ pos, i });

                    s1[s[pos] - 'a'].insert(pos);
                }
            }

            cout << ans.size() << '\n';
            for (auto i : ans) {
                cout << i.first + 1 << " " << i.second + 1 << '\n';
            }
        }
        else {
            cout << "No\n";
        }
    }

    //system("pause");
    return 0;
}