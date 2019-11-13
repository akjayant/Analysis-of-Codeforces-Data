#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string& s, string& t) {
        vector<size_t> pos;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == t[i])
                continue;
            pos.push_back(i);
        }
        return pos.empty() || (pos.size() == 2 && s[pos[0]] == s[pos[1]] && t[pos[1]] == t[pos[0]]);
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
        bool result = Solution().solve(s, t);
        if (result) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}