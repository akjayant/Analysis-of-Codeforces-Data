#include <iostream>
#include <vector>
using namespace std;

string s1, s2;
vector <pair <int, int>> ans;


void f() {
    ans.clear();
    int n;
    cin >> n;
    cin >> s1 >> s2;
    for (int i = 0; i < (int) s1.size(); i++) {
        if (s1[i] != s2[i]) {
            int j = i + 1;
            while (j < n)
                if (s2[j] != s2[i])
                    j++;
                else
                    break;
            if (j < n) {
                swap(s1[i], s2[j]);
                ans.emplace_back(i + 1, j + 1);
            } else {
                j = i + 1;
                while (j < n)
                    if (s1[j] != s2[i])
                        j++;
                    else
                        break;
                if (j < n) {
                    ans.emplace_back(j + 1, n);
                    ans.emplace_back(i + 1, n);
                    swap(s1[j], s2[n - 1]);
                    swap(s1[i], s2[n - 1]);
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl << ans.size() << endl;
    for (auto i : ans)
        cout << i.first << " " << i.second << endl;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        f();
    }
    return 0;
}
