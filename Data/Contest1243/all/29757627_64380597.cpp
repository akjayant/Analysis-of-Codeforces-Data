#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int q, n;
vector<int> v;

int main(){



    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        v.clear();
        for (int i = 0; i < n; ++i) if (a[i] != b[i]) v.push_back(i);
        if (v.size() == 1 || v.size() > 2){cout << "No\n"; continue;}
        if (v.size() && a[v[0]] == a[v[1]] && b[v[1]] == b[v[0]]) cout << "Yes\n";
        else if (v.empty()) cout << "Yes\n";
        else cout << "No\n";
    }


}
