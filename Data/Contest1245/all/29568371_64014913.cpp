#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s; cin >> s;
        int ans = 0;
        char p[n]; vector < bool > us(n);
        for(int i = 0; i < n; ++i){
            if(s[i] == 'R'){
                if(b){
                    --b; us[i] = true;
                    p[i] = 'P';
                }
            }
            if(s[i] == 'P'){
                if(c){
                    --c; us[i] = true;
                    p[i] = 'S';
                }
            }
            if(s[i] == 'S'){
                if(a){
                    --a; us[i] = true;
                    p[i] = 'R';
                }
            }
        }
        for(int i = 0; i < n; ++i){
            if(!us[i]){
                if(a){
                    p[i] = 'R'; --a; continue;
                }
                if(b){
                    p[i] = 'P'; --b; continue;
                }
                if(c){
                    p[i] = 'S'; --c; continue;
                }
            }
            else{
                ++ans;
            }
        }
        if(ans >= (n + 1) / 2){
            cout << "YES" << endl;
            for(int i = 0; i < n; ++i){
                cout << p[i];
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
