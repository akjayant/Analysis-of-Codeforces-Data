#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
int pos[maxn];
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for(int i = 0; s[i]; i++){
            if(s[i] == '1'){
                ans = max(ans, max((i + 1) * 2, (n - i) * 2));
            }
        }
        cout << ans << endl;


    }
}
