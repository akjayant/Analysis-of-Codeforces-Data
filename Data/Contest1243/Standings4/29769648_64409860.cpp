#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using db = double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
const int N = 2e5 + 10;
const ll inf = 1e15 + 42;
#define endl "\n"
const ll mod = 1000000007;
 
void testCase() {
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector <int> indx;
        for (int i=0; i<n; i++) {
            if (s[i] == t[i]) {

            }
            else if (s[i] != t[i]) {
                indx.push_back (i);
            }
        }
        //remove equal one
        vector <pair<int, int>> ans;
        int vv[n+3] = {0};
        int n1 = indx.size();
        int cnt = 0;
        int flg = 1;
        for (int i=0; i<n1 && ans.size()<=2*n && cnt<n1; i++) {
            //find indx with equal
            int i1 = indx[i];
            if (vv[i1] == 0) {
                int ok = 0;
                for (int j=i+1; j<n1; j++) {
                    int j1 = indx[j];
                    if (vv[j1] == 0) {
                        if (s[i1]==s[j1] && t[i1]==t[j1]) {
                            ans.push_back (make_pair(i1, j1));
                            vv[i1] = vv[j1] = 1; 
                            ok = 1;
                            cnt+=2;
                            break;
                        }
                    }
                }
                int temp1 = -1;
                int temp2 = -1;
                if (ok == 0) {
                    //find another pair for i
                    for (int j=i+1; j<n1; j++) {
                        int j1 = indx[j];
                        if (vv[j1] == 0) {
                            if (s[i1]==s[j1]) {
                                ans.push_back (make_pair(j1, i1));
                                vv[i1] = 1;
                                ok = 1;
                                cnt++;
                                s[j1] = t[i1];
                                break;
                            }
                            else if (t[i1]==t[j1]) {
                                ans.push_back (make_pair(i1, j1));
                                vv[i1] = 1;
                                ok = 1;
                                cnt++;
                                t[j1] = s[i1];
                                break;
                            }
                            else if (s[i1]==t[j1]) {
                                temp1 = j1;
                            }
                            else if (t[i1] == s[j1]) {
                                temp2 = j1;
                            }
                        }
                    }
                }
                if (ok == 0) {
                    if (temp1 != -1) {
                        ans.push_back (make_pair(temp1, temp1));
                        t[temp1] = s[temp1];
                        ans.push_back (make_pair(temp1, i1));
                        s[temp1] = t[i1];
                        vv[i1] = 1;
                        ok = 1;
                        cnt++;
                    }
                    else if (temp2 != -1) {
                        ans.push_back (make_pair(temp2, temp2));
                        s[temp2] = t[temp2];
                        ans.push_back (make_pair(i1, temp2));
                        t[temp2] = s[i1];
                        vv[i1] = 1;
                        ok = 1;
                        cnt++;
                    }
                }
                for (int j=i+1; j<n1; j++) {
                    int j1 = indx[j];
                    if (vv[j1] == 0) {
                        if (s[j1] == t[j1]) {
                            cnt++;
                            vv[j1] = 1;
                        }
                    }
                }
                if (vv[i1] == 0) {
                    flg = 0;
                    break;
                }
            }
        }
        if (flg == 0) {
            cout << "NO" << endl;
        }
        else if (cnt != n1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << ans.size() << endl;
            for (int i=0; i<ans.size(); i++) {
                cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
            }
        }
    }
}
 
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    testCase();
    return 0;
}