#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back;
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>

#ifdef LOCAL
#define debug(x) cout<<#x<<" "<<(x)<<endl;
#else
#define debug(x)
#endif

struct fast_io{
    fast_io(){
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        cout<<fixed<<setprecision(12);
    }
}____;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        string s;
        cin>>n>>s;
        int c = 0;
        int ans = n;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                c++;
                ans = max(ans, max(n + c, max(2 * (i + 1), 2 * (n - i))));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
