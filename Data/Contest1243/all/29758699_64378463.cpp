#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3 + 9 ;
int a[N];
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1 ; i <= n ; ++i) cin >> a[i];
       sort(a+1 , a +n+1);
       int j = 1;
       for(int i = n   ; i>=1 ; --i , ++j){
        ans = max(ans , min( j , a[i]));
       }
       cout << ans << endl;
    }
    return 0;
}
