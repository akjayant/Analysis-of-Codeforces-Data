#include <bits/stdc++.h>
#define PI 2*asin(1)
#define int long long
#define mod 1000000007
#define all(a) begin(a),end(a)
#define fore(i, j, n) for(long long i = j; i < n;i++)

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int res = 0;
    int c = 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            if(res == 0) res = i;
            c++;
            while(n % i == 0) n /= i;
        }
    }
    bool flag = true;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            flag = false;
            break;
        }
    }
    if(flag && n != 1){
        c++;
        if(res == 0) res = n;
    }
    if(c > 0 ){
        if(c == 1) cout << res;
        else cout << 1;
    }else
    cout << n;
    return 0;
}