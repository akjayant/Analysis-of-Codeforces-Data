#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

bool checkPossible(int n, string s, string t) {
    int ch[26];
    memset(ch, 0, sizeof(ch));
    for(int i = 0; i < n; ++i) {
        ++ch[s[i]-'a'];
        ++ch[t[i]-'a'];
    }
    for(int i = 0; i < 26; ++i) {
        if(ch[i] & 1) {
            return false;
        }
    }
    return true;
}

int findChar(string s, int start, int end, char c) {
    for(int i = start; i < end; ++i) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}

int32_t main() {
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<pair<int,int> > swaps;
        if(checkPossible(n, s, t)) {
            cout << "Yes\n";
            for(int i = 0; i < n; ++i) {
                if(s[i] != t[i]) {
                    int pos = findChar(s, i+1, n, s[i]);
                    if(pos == -1) {
                        pos = findChar(t, i+1, n, s[i]);
                        char temp = t[pos];
                        t[pos] = s[i+1];
                        s[i+1] = temp;
                        swaps.push_back(make_pair(i+2, pos+1));
                        temp = s[i+1];
                        s[i+1] = t[i];
                        t[i] = temp;
                        swaps.push_back(make_pair(i+2, i+1));
                    } else {
                        char temp = s[pos];
                        s[pos] = t[i];
                        t[i] = temp;
                        swaps.push_back(make_pair(pos+1, i+1));
                    }
                }
            }
            cout << swaps.size() << '\n';
            for(int i = 0; i < swaps.size(); ++i) {
                cout << swaps[i].first << ' ' << swaps[i].second << '\n';
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}