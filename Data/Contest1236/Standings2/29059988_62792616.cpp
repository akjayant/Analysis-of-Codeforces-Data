#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int N=500,mod=1e9+7;
ll ans[N][N];
int32_t main(){
    ll n;
    cin >> n;
    ll cnt=1;
    for (int i=0;i<n;i++){
        if (i%2==0){
            for (int j=0;j<n;j++){
                ans[j][i]=cnt;
                cnt++;
            }
        }
        else{
            for (int j=n-1;j>-1;j--){
                ans[j][i]=cnt;
                cnt++;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}































