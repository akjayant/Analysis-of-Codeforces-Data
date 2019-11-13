/// Quality Over Quantity
 
#include <bits/stdc++.h>
 
#define FILE_NAME "C"
 
using namespace std;
using ll = long long;
 
#define f first
#define s second 
#define pb push_back
#define pp pop_back
#define SZ(x) ((int) x.size())
#define all(x) x.begin(), x.end()
#define what_is(x) cerr << #x << " is " << x << endl;
 
void freekick() {
#ifndef ONLINE_JUDGE
    freopen(FILE_NAME".in", "r", stdin);
    freopen(FILE_NAME".out", "w", stdout);
#endif
}

const int INF_MAX = 3e5 + 100; 
const int DX[] = {+1, 0, -1, 0, +1, +1, -1, -1};
const int DY[] = {0, +1, 0, -1, +1, -1, +1, -1};
 
void freegoal() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
}
 
int a[INF_MAX];
int like[INF_MAX];
signed main() {
    freekick();
    freegoal();   
    int tedy; cin >> tedy;
    for (int smash = 1; smash <= tedy; smash++) {
        int n; cin >> n; string str, tedy;
        cin >> str >> tedy; vector<int> geforce;
        for (int i = 0; i < n; i++) {
            if (str[i] != tedy[i]) {
                like[str[i] - '0']++; like[tedy[i] - '0']++; geforce.pb(i);
            }
        }
        bool was = false;
        for (int i = 0; i < 30; i++) {
            if (like[i] % 2) { was = true;
                cout << "No" << endl; break;
            }
        }
        if (was)
            continue;
        bool discontribute = 0;
        int middle = (int) SZ(geforce);
        vector<pair<int, int> > samsung;
        for (int i = 0; i < middle; i++) {
            if (str[geforce[i]] == tedy[geforce[i]]) continue; was = false;
            for (int j = i + 1; j < middle; j++) { if (tedy[geforce[i]] == tedy[geforce[j]]) {
                    samsung.pb(make_pair(geforce[i], geforce[j]));
                    swap(str[geforce[i]], tedy[geforce[j]]);
                    was = true; break;
                }
            }
            if (was)
                continue;;
            for (int j = i + 1; j < middle; j++) {
                if (tedy[geforce[i]] == str[geforce[j]]) {
                    samsung.pb(make_pair(geforce[j], geforce[j])); swap(str[geforce[j]], tedy[geforce[j]]);
                    samsung.pb(make_pair(geforce[i], geforce[j])); swap(str[geforce[i]], tedy[geforce[j]]);
                    was = true; break;
                }
            }
            if (was == 0) {
                discontribute = true;
                cout << "No" << endl;
                break;
            }
        }
        if (discontribute)
            continue;
        cout << "Yes" << endl; cout << (int) SZ(samsung) << endl;
        for (int i = 0; i < SZ(samsung); i++) { cout << samsung[i].first + 1 << " " << samsung[i].second + 1 << endl; }
    }
    return false;
}