#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 5;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s ;
        int n ;
        cin >> n;
        cin >> s;
        int fir = -1, sec = -1, ans = s.size();
        for(int i = 0 ; i < s.size() ; i++){
            if (fir == -1 && s[i] == '1')
                fir = i;
            if (s[i] == '1')
                sec = i;
        }
        if (fir != -1){
            ans = max(ans, fir + 1 + int(s.size()) - fir);
            ans = max(ans, sec + 1 + sec + 1);
        }
        reverse(s.begin(),s.end());
        fir = -1, sec = -1;
        for(int i = 0 ; i < s.size() ; i++){
            if (fir == -1 && s[i] == '1')
                fir = i;
            if (s[i] == '1')
                sec = i;
        }
        if (fir != -1){
            ans = max(ans, fir + 1 + int(s.size()) - fir);
            ans = max(ans, sec + 1 + sec + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}