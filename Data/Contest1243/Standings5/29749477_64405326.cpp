#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        string str1, str2;
        cin >> str1 >> str2;
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (str1[i] != str2[i]) {
                bool ch = true;
                for (int j = i + 1; j < n; ++j) {
                    if (str1[i] == str1[j]) {
                        swap(str2[i], str1[j]);
                        ++cnt;
                        ans.push_back(j + 1);
                        ans.push_back(i + 1);
                        ch = false;
                        break;
                    }
                    else
                        if (str2[i] == str2[j]) {
                            swap(str1[i], str2[j]);
                            ++cnt;
                            ans.push_back(i + 1);
                            ans.push_back(j + 1);
                            ch = false;
                            break;
                        }
                        else
                            if (str1[i] == str2[j]) {
                                swap(str1[j], str2[j]);
                                swap(str2[i], str1[j]);
                                ++cnt;
                                ++cnt;
                                ans.push_back(j + 1);
                                ans.push_back(j + 1);
                                ans.push_back(j + 1);
                                ans.push_back(i + 1);
                                ch = false;
                                break;
                            }
                            else
                                if (str2[i] == str1[j]) {
                                    swap(str1[j], str2[j]);
                                    swap(str1[i], str2[j]);
                                    ++cnt;
                                    ++cnt;
                                    ans.push_back(j + 1);
                                    ans.push_back(j + 1);
                                    ans.push_back(i + 1);
                                    ans.push_back(j + 1);
                                    ch = false;
                                    break;
                                }
                }
                if (ch)
                    goto l;
            }
        }
        if (cnt > 2 * n) {
            l:
            cout << "No\n";
            continue;;
        }
        cout << "Yes\n";
        cout << cnt << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << ' ';
            if (i % 2)
                cout << '\n';
        }
    }
    return 0;
}