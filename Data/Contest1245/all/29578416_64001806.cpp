#include <bits/stdc++.h>
using namespace std;

void run();

signed main(){
    cout.setf(ios::fixed);
    cout.precision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

void run(){
    int t;
    cin >> t;
    while(t--){
        vector <int> v(3); // R P S
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s;
        cin >> s;
        for (auto &i: s){
            if (i == 'R'){
                v[0]++;
            } else if (i == 'P'){
                v[1]++;
            } else{
                v[2]++;
            }
        }
        int cnt = 0;
        cnt += min(v[2], a);
        cnt += min(v[0], b);
        cnt += min(v[1], c);
        if (cnt >= (n + 1) / 2){
            vector <char> ans(n, 0);
            for (int i = 0; i < n; i++){
                if (s[i] == 'R'){
                    if (b){
                        ans[i] = 'P';
                        b--;
                    }
                } else if (s[i] == 'P'){
                    if (c){
                        ans[i] = 'S';
                        c--;
                    }
                } else{
                    if (a){
                        ans[i] = 'R';
                        a--;
                    }
                }
            }
            for (int i = 0; i < n; i++){
                if (ans[i] != 0)
                    continue;
                if (b){
                    ans[i] = 'P';
                    b--;
                } else if (a){
                    ans[i] = 'R';
                    a--;
                } else if (c){
                    ans[i] = 'S';
                    c--;
                }
            }
            cout << "YES\n";
            for (auto &i: ans)
                cout << i;
            cout << '\n';
        } else{
            cout << "NO\n";
        }

    }
}




