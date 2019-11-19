#include<bits/stdc++.h>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mod 1000000007
#define INF 1e18
#define ALPHABET_SIZE 26


using namespace std;
typedef long long ll;

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/


int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int ans = n;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                ans = max(ans, 2 * n - 2 * i);
                ans = max(ans, 2 * i + 2);
                ans = max(ans, n + 1);
            }
        }
        cout << ans << "\n";

    }
}
