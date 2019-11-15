#include <bits/stdc++.h>

using namespace std;



int k, n;

int check(string & s, int i, int value) {
    for (int index = i + 1; index < n; index++) {
        if (s[index] == value) return index;
    }
    return -1;
}

string s, t;

const int maxn = 55;

int s_done[maxn];
int t_done[maxn];

map<char, set<int>> char_to_s_indices;
map<char, set<int>> char_to_t_indices;
vector<pair<int, int>> ans;

int valid(int n) {
    map<char, int> freq;
    for (int i = 0; i < (int)s.size(); i++) {
        freq[s[i]]++;
        freq[t[i]]++;
    }
    for (pair<char, int> p: freq) {
        if (p.second % 2 != 0) return 0;
    }
    return 1;
}


void fix(int i) {
    if (s[i] == t[i]) return;
    int s_index = check(s, i, s[i]);
    int t_index = check(t, i, t[i]);
    if (s_index != -1) {
        swap(t[i], s[s_index]);
        ans.push_back({s_index, i});
        return;
    }
    if (t_index != -1) {
        swap(s[i], t[t_index]);
        ans.push_back({i, t_index});
        return;
    }

    int bottom_index = check(t, i, s[i]); //valid
    int top_index = check(s, i, t[i]); //valid
    swap(s[top_index], t[bottom_index]);
    swap(s[i], t[bottom_index]);
    ans.push_back({top_index, bottom_index});
    ans.push_back({i, bottom_index});
}

void print() {
    int l = ans.size();
    cout << l << "\n";
    for (int i = 0; i < l; i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";

    }
}

int main() {
    // freopen("B2.in", "r", stdin);
    // freopen("B2.out", "w", stdout);
    cin >> k;
    for (int cs = 1; cs <= k; cs++) {
        cin >> n >> s >> t;
        if (valid(n)) {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                fix(i);
            }
            
            print();
        } else {
            cout << "No\n";
        }
        memset(s_done, 0, sizeof(s_done));
        memset(t_done, 0, sizeof(t_done));
        ans.clear();
    }
}