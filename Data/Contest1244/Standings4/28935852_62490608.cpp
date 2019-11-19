#include <bits/stdc++.h>

#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
const int maxn = 3e5+35;
int main(){
    int T,n; cin >> T;
    string s;
    while(T--){
         cin >> n >> s;
         if(s[0]=='1'||s[n-1]=='1'){
             cout << 2*n << endl;
         }else{
             int pos1 = 0;
             for(int i = 0;i < n; ++i){
                 if(s[i] == '1'){
                     pos1 = i; break;
                 }
             }
             int pos2 = 0;
             for(int i = n-1; ~i; --i){
                 if(s[i] == '1'){
                     pos2 = i;
                     break;
                 }
             }
             int ans = n;
             if(pos1) ans = max(ans,(n-pos1)*2);
             if(pos2) ans = max(ans,(pos2+1)*2);
             cout << ans << '\n';
         }
    }
    return 0;
}