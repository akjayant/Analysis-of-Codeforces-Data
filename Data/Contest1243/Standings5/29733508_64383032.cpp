
 #include<bits/stdc++.h>

 using namespace std;
 #define task "data"
 #define int long long
 const int maxn = 1e5 + 5;
 int k , n , a[maxn];
 string s , t;
 main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     #ifndef ONLINE_JUDGE
     freopen(task".inp","r",stdin);
     freopen(task".out","w",stdout);
     #endif // ONLINE_JUDGE

     cin >> k;

     while(k--) {
        cin >> n;
        cin >> s >> t;
        s = " " + s; t = " " +t;
        vector<char> vec , vec1;
        vec.clear();
        vec1.clear();
        int tt(0);
        for (int i = 1 ; i <= n ; i++) {
             if(s[i] != t[i]) {
                tt++;
                vec.push_back(s[i]);
                vec1.push_back(t[i]);
             }
        }
        if(tt == 0) cout << "Yes" << "\n";
        else if(tt == 2) {
            if(vec[0] == vec[1] && vec1[1] == vec1[0]) {
                cout << "Yes" << "\n";
            }
            else cout << "No" << "\n";
        }
        else cout << "No" << "\n";

     }

 }
