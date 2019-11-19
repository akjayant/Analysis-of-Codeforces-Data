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
const int N=1e5+100;
ll a[N];
ll par[N];

int32_t main(){
    sync;
    ll n, k;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans=1e9+100;
    sort(a+1,a+1+n);

    for (int i=1;i<=n;i++){
        par[i]=par[i-1]+a[i];
    }
    for (int i=1;i<=n;i++){
        ll z=i*a[i]-par[i];
        z=k-z;
        if (z<0){
            continue;
        }
        //cout << a[i] << " " << z << endl;
        ll l=a[i]-1,r=a[n];
        while(r-l>1){
            ll mid=(r+l)/2;
            ll w=lower_bound(a+1,a+n+1,mid)-a;

            ll s=par[n]-par[w-1];

            s-=(n-w+1)*mid;
          //  cout << mid << " " << w << " " << s << endl;
            if (s<=z){
                r=mid;
            }
            else{
                l=mid;
            }
        }
     //   cout << r << endl;
        ans=min(ans,r-a[i]);

    }
    for (int i=1;i<=n;i++){
        ll z=par[n]-par[i-1]-(n-i+1)*a[i];
        z=k-z;
        if (z<0){
            continue;
        }
        //cout << a[i] << " " << z << endl;
        ll l=a[0],r=a[i]+1;
        while(r-l>1){
            ll mid=(r+l)/2;
            ll w=upper_bound(a+1,a+n+1,mid)-a;
            w--;
            ll s=-par[w];

            s+=w*mid;
          //  cout << mid << " " << w << " " << s << endl;
            if (s<=z){
                l=mid;
            }
            else{
                r=mid;
            }
        }
     //   cout << r << endl;
        ans=min(ans,a[i]-l);


    }
    cout << ans;

}



















