#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<bool, vector<pair<size_t, size_t>>> solve(string& s, string& t) {
        unordered_map<char, int> chars;
        for (char c : s)
            ++chars[c];
        for (char c : t)
            ++chars[c];
        for (const auto ch : chars) {
            if (ch.second % 2)
                return {false, {}};
        }
        unordered_map<char, pair<set<size_t>, set<size_t>>> pos;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == t[i])
                continue;
            pos[s[i]].first.insert(i);
            pos[t[i]].second.insert(i);
        }
        vector<pair<size_t, size_t>> result;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == t[i])
                continue;
            if (pos[s[i]].first.size() >= 2) {
                size_t second = *next(pos[s[i]].first.begin());
                result.push_back({second + 1, i + 1});
                pos[s[i]].first.erase(i);
                pos[s[i]].first.erase(second);
                pos[t[i]].second.erase(i);
                pos[t[i]].first.insert(second);
                swap(t[i], s[second]);
                if (s[second] == t[second]) {
                    pos[s[second]].first.erase(second);
                    pos[s[second]].second.erase(second);
                }
            } else {
                size_t second = *(pos[s[i]].second.begin());
                result.push_back({second + 1, second + 1});
                result.push_back({second + 1, i + 1});
                pos[s[i]].first.erase(i);
                pos[s[i]].second.erase(second);
                pos[s[second]].first.erase(second);
                pos[s[second]].second.insert(second);
                pos[t[i]].second.erase(i);
                pos[t[i]].first.insert(second);
                swap(t[second], s[second]);
                swap(t[i], s[second]);
                if (s[second] == t[second]) {
                    pos[s[second]].first.erase(second);
                    pos[s[second]].second.erase(second);
                }
            }
        }
        return {true, move(result)};
    }
};

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        auto result = Solution().solve(s, t);
        if (result.first) {
            cout << "Yes" << endl;
            cout << result.second.size() << endl;
            for (const auto& v : result.second) {
                cout << v.first << ' ' << v.second << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}