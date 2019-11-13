
 #include<bits/stdc++.h>

 using namespace std;
 #define task "data"
 #define int long long
 const int maxn = 1e5 + 5;
 int k , n , a[maxn];
 main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     #ifndef ONLINE_JUDGE
     freopen(task".inp","r",stdin);
     freopen(task".out","w",stdout);
     #endif // ONLINE_JUDGE

     cin >> k;

     while(k--){
        cin >> n;
        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        sort(a + 1 , a + n + 1);
        int ans(0);
        for (int i = n ; i >= 1 ; i--) {
            if(a[n - i + 1] >= i) { cout << i << endl; break;}
        }
     }

 }
