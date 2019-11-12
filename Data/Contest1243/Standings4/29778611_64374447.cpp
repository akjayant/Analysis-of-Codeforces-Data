#define pb push_back
#define mod 1000000009
#define ff first
#define ss second
#define maxn 100005
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


int main(int argc, char const *argv[]) {
    int tc;
    cin >> tc;
    while(tc--){
        vector<int> v;
        int n, x, k = 0, res = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> x;
            v.pb(x);
        }
        sort(v.rbegin(), v.rend());
        for(int i=0;i<n;i++){
            k++;
            res = max(res, min(v[i], k));
        }
        cout << res << endl;
    }

    return 0;
}
