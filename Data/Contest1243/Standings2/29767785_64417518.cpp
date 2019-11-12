#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int n, string a, string b) {
    vector<int> v(30);
    
    for (int i = 0; i < n; i++) {
        v[a[i]-'a']++;
        v[b[i]-'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 == 1) return false;
    }
    return true;
}

void solve() {
    int n;
    string a, b;
    
    cin >> n;
    cin >> a >> b;
    
    if (!isPossible(n, a, b)) {
        cout << "No" << endl;
        return;
    } else {
        cout << "Yes" << endl;
    }
    
    vector< pair<int,int> > ans;
    vector<int> va, vb;
    
    while (a != b) {
        bool isCont = false;
//        cout << a << ' ' << b << endl;
        va.assign(26, -1);
        vb.assign(26, -1);
        
        int safe = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            
            safe = i;
            int ai = a[i]-'a';
            int bi = b[i]-'a';
            
            if (va[ai] > -1) {
                int ia = va[ai];
                int ib = i;
                ans.push_back(make_pair(ia, ib));
                char ch = a[ia];
                a[ia] = b[ib];
                b[ib] = ch;
                
                isCont = true;
                break;
            }
            
            if (vb[bi] > -1) {
                int ia = i;
                int ib = vb[bi];
                ans.push_back(make_pair(ia, ib));
                char ch = a[ia];
                a[ia] = b[ib];
                b[ib] = ch;
                
                isCont = true;
                continue;
            }
            
            va[ai] = i;
            vb[bi] = i;
        }
        
        if (isCont) continue;
        int ia = safe;
        int ib = safe;
        ans.push_back(make_pair(ia, ib));
        char ch = a[ia];
        a[ia] = b[ib];
        b[ib] = ch;
    }
    
    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }
}

int main() {
    int k;
    cin >> k;

    while (k--) {
        solve();
    }
}
