#include<bits/stdc++.h>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mod 1000000007
#define INF 1e18
#define ALPHABET_SIZE 26


using namespace std;
typedef long long ll;

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/

long long n, k;
long long a[100005];
long long pref[100005];

long long hitung(long long kiri, long long kanan){
    int pos1 = lower_bound(a + 1, a + n + 1, kiri) - a;
    int pos2 = upper_bound(a + 1, a + n + 1, kanan) - a;

    long long ret;
    ret = kiri * (pos1 - 1) - pref[pos1 - 1];
    ret = ret + (pref[n] - pref[pos2 - 1]) - kanan * (n - pos2 + 1);

    return ret;
}

long long solve(long long now){

    long long l = 1;
    long long r = 1e9;

    long long ret = 1e18;
    while(l + 3 <= r){
        // cout << l << " " << r << " ini\n";
        long long mid1 = (l * 2 + r) / 3;
        long long mid2 = (r * 2 + l) / 3;

        long long a = hitung(mid1, mid1 + now);
        long long b = hitung(mid2, mid2 + now);
        ret = min(ret, a);
        ret = min(ret, b);

        if(a < b){
            r = mid2;
        }else{
            l = mid1;
        }
    }
    for(long long i = l; i <= r; i++){
        // cout << i << " " << i + now << " " << hitung(i, i + now) << " oi\n";
        ret = min(ret, hitung(i, i + now));
    }

    return ret;

}

int main(){
    cin >> n >> k;

    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++ ){
        pref[i] = pref[i - 1] + a[i];
    }

        

    //binser answer
    long long l = 0;
    long long r = 1e9;

    long long ans = 1e18;
    while(l <= r){
        long long mid = (l + r)/2;

        long long now = solve(mid);

        // cout << now << " " << mid << " here\n";
        if(now <= k){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    cout << ans << "\n";

}
