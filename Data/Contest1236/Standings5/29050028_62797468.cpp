/*input
3
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    IOS;
    int n;
    cin >> n;
    vector<int> v[n+1];
    int ct = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i%2 == 1){
                v[j].pb(ct);
            }
            else{
                v[n - j + 1].pb(ct);
            }
            ct++;
        }
    }
    for(int i = 1; i <= n ; i++){
        for(auto x : v[i]){
            cout << x << " ";
        }
        cout << endl;
    }
return 0;
}
