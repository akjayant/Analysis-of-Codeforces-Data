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

const int N=2e5+100;

int32_t main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans=0;
    ll l=1,r=1;
    ll e=0;
    for (int i=0;i<n;i++){
        if (s[i]=='('){
            e++;
        }
        else{
            e--;
        }
    }
    if (e!=0){
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            swap(s[i],s[j]);

            ll cnt=0;
            ll w=0;
            ll z=0;
            for (int k=0;k<n;k++){
                if (s[k]=='('){
                    cnt++;
                }
                else{
                    cnt--;
                }

                w=min(w,cnt);
            }
            for (int k=n-1;k>-1;k--){
                if (s[k]=='('){
                        w++;
                    }
                else{
                    w--;
                }
                if (w==0){
                    z++;
                }
            }
            if (ans<z){
                ans=z   ;
                l=i+1;
                r=j+1;
            }
            swap(s[i],s[j]);
        }

    }
    cout << ans << endl;
    cout << l << " " << r << endl;
}

























