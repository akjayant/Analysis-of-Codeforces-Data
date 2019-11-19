#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, k, a[100001], l, r;

signed main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    l = 1, r = n;
    while(1){
        if(l == r){
            cout << 0;
            return 0;
        }
        if(l <= (n + 1 - r)){
            if(((a[l + 1] - a[l]) * l) <= k){
                k -= ((a[l + 1] - a[l]) * l);
                l++;
            }
            else{
                cout << a[r] - a[l] - (k / l);
                return 0;
            }
        }
        else{
            if(((a[r] - a[r - 1]) * (n + 1 - r)) <= k){
                k -= ((a[r] - a[r - 1]) * (n + 1 - r));
                r--;
            }
            else{
                cout << a[r] - a[l] - (k / (n + 1 - r));
                return 0;
            }
        }
    }
}