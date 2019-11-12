#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;

int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--){
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector <int> pos;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]) pos.push_back(i);
        if (pos.size() == 0){
            cout << "Yes\n";
        }if (pos.size() == 2){
            if (s[pos[0]] == s[pos[1]] && t[pos[0]] == t[pos[1]]) cout << "Yes\n";
            else cout << "No\n";
        }else cout << "No\n";
//        map <char, int> b;
//        for (int i = 0; i < n; i++) b[s[i]]++;
//        for (int i = 0; i < n; i++) b[t[i]]++;
//        int can = 1;
//        for (auto u: b){
//            if (u.second & 1){
//                can = 0;
//            }
//        }
//        if (can) cout << "Yes\n";
//        else cout << "No\n";
    }
}
