#include<bits/stdc++.h>

#define LL long long
using namespace std;
const long long mod = 1000000000 + 7;


vector<char> a, b;
int c[100];
int d[100];

int main() {
    //freopen("C:\\Users\\93569\\Desktop\\untitled\\a.txt", "r", stdin);
//    freopen("s","r",stdin)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        a.clear();
        b.clear();
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        string s, t;
        int n;
        cin >> n;
        cin >> s;
        cin >> t;
        for (auto i:s) {
            c[i - 'a']++;
            d[i - 'a']++;
        }
        for (auto i:t) {
            c[i - 'a']++;
        }
        int flag = 0;
        for (int i = 0; i <= (int) ('z' - 'a'); i++) {
            if (c[i] % 2 == 1) {
                cout << "No" << endl;
                flag = 1;
                break;
            }
            c[i] /= 2;
            d[i] -= c[i];
        }
        if (flag == 1) continue;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                a.push_back(s[i]);
                b.push_back(t[i]);
            }
        }
        if (a.size() > 2) {
            cout << "No" << endl;
        } else {
            if (a.empty()) {
                cout << "Yes" << endl;
            } else {
               if(a[0]==a[1]&&b[0]==b[1]){
                   cout<<"yes"<<endl;
               }
               else{
                   cout<<"No"<<endl;
               }
            
            }
        }


        //cout << "Yes" << endl;

    }
    return 0;
}