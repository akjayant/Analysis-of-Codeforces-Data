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
        int a, b;
        cin >> a >> b;
        if(__gcd(a, b) == 1) {
            cout << "Finite\n";
        }
        else {
            cout << "Infinite\n";
        }
    }

    return 0;
}