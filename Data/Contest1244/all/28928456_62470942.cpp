#include<bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        int fir = -1, sec = -1;
        for(int z = 0 ; z < s.size(); ++z){
            if(s[z] == '1'){fir = z;break;}
        }
        for(int z = s.size() - 1 ; z >= 0; --z){
            if(s[z] == '1'){sec = z;break;}
        }
        if(sec != -1)
        ans = max(ans , 2 * (sec + 1));
        if(fir != -1)
        ans = max(ans , (n - fir) * 2);
        cout << ans << '\n';
    }
    return 0;
}
