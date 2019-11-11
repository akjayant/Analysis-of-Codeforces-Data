#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>  
#define ll long long
#define ff first 
#define ss second
#define pb push_back
#define rep(i,a,b)  for (__typeof((b)) i=(a);i<=(b);i++)
#define nrep(i,a,b)  for (__typeof((b)) i=(b);i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
const ll N = 1e5 + 5;
const ll N1 = 3e5 + 5;
const int LOGN = 17;
const ll mod = 1e9 + 7;


int main() {

    int t;
    cin >> t;
    while(t--) {
        int n, b, c, a;
        cin >> n >> a >> b >> c;

        string s;
        cin >> s;

        vector <char> ans(n, 'q');
        int ct = 0;

        for(int i=0;i<n;i++) {
            if(s[i] == 'R') {
                if(b > 0) {
                    b--;
                    ans[i] = 'P';
                    ct++;
                }
            }
            else if(s[i] == 'P') {
                if(c > 0) {
                    c--;
                    ans[i] = 'S';
                    ct++;
                }
            }
            else {
                if(a > 0) {
                    a--;
                    ans[i] = 'R';
                    ct++;
                }
            }
        }
        if(ct >= (ceil)((double)n / (double)2)) {
            cout << "YES\n";
            for(int i=0;i<n;i++) {
                if(ans[i] != 'q') {
                    cout << ans[i];
                }
                else {
                    if(a > 0) {
                        cout << "R";
                        a--;
                    }
                    else if(b > 0) {
                        cout << "P";
                        b--;
                    }
                    else {
                        cout << "S";
                        c--;
                    }
                }
            }
            cout << "\n";
        }
        else {
            cout << "No\n";
        }

    }

    return 0;
}