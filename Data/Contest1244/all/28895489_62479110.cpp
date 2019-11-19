#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 2e5 + 5, MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s = "";
        cin>>s;
        vector<int> st;
        if(n == 1 and s[0] == '1'){
            cout<<2<<endl;
            continue;
        }
        else if(n == 1 and s[0] == '0'){
            cout<<1<<endl;
            continue;
        }

        for(int i = 0; i < n; i++){
            if(s[i] == '1') st.pb(i);
        }
        if(st.size() == 0){
            cout<<n<<endl;
            continue;
        }

        int ans = n;
        if(st.size() == 1){
            int p1 = 2*st[0] + 2;
            ans = max(ans, p1);
            st[0] = (n - 1 - st[0]);
            p1 = 2*st[0] + 2;
            ans = max(ans, p1);
            cout<<ans<<endl;
            continue;
        }
        int sz = st.size();
        int d1 = st[0], d2 = st[sz - 1];
        int val = 2*d2 + 2;

        d2 = (n - 1 - d2);
        val = max(val, 2LL*d2 + 2LL);
        val = max(val, 2LL*d1 + 2LL);

        d1 = (n - 1 - d1);
        val = max(val, 2LL*d1 + 2LL);

        ans = max(ans, val);
        cout<<ans<<endl;

    }



    return 0;
}
