#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <istream>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <set>
#include <cmath>
#include <random>
#include <iostream>
#include <bitset>
#include <iomanip>
#include <queue>
#include <string>

#define int long long
#define endl "\n"
#define all(x) x.begin(),x.end()
#define rr return 0
#define xx first
#define yy second
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0;i < n;i++){
            int j = i;
            int tmp = 0;
            while(j < n){
                if(s[j] == '1')
                    tmp += 2;
                else
                    tmp++;
                j++;
            }
            ans = max(ans, tmp);
            tmp = 0;
            j = i;
            while(j >= 0){
                if(s[j] == '1')
                    tmp += 2;
                else
                    tmp++;
                j--;
            }
            ans = max(ans, tmp);
        }
        int mn, mx;
        mx = -1;
        mn = 1e9;
        for(int i = 0;i < n;i++){
            if(s[i] == '1'){
                mx = max(mx, i + 1);
                mn = min(mn, i + 1);
            }
        }
        ans = max(ans, mx * 2);
        ans = max(ans, (n - mn + 1) * 2);
//        if(s[0] == '1' || s[n - 1] == '1'){
//            ans = 2 * n;
//        }
        cout << ans << endl;
    }
    rr;
}
