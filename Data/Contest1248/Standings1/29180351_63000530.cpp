#include <bits/stdc++.h>
using namespace std;
int calc(const string& s) {
    string ss = s + s;
    stack<char> stk;
    int curLen = 0;
    int ans = 0;
    bool good = 0;
    for(int i = 0; i < ss.size(); ++i) {
        char cur = ss[i];
        ++curLen;
        if(cur == '(') {
            stk.push(cur);
        }
        else {
            if(stk.empty()) {
                curLen = 0;
                ans = 0;
            }
            else {
                stk.pop();
                ans += stk.empty();
            }
        }

        if(stk.empty() and curLen == s.size()) {
            good = 1;
            break;
        }
    }
    if(!good) return 0;
    else return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string str;
    cin >> str;
    long long ans = calc(str), l = 1, r = 1;
    for(int i = 0; i < str.size(); ++i)
        for(int j = i+1; j < str.size(); ++j) {
            if(str[i] == str[j]) continue;
            swap(str[i], str[j]);
            int t = calc(str);
            if(t > ans)
                ans = t, l = i+1, r = j+1;
            swap(str[i], str[j]);
        }
    cout << ans << endl;
    cout << l << ' ' << r << endl;
    return 0;
}
