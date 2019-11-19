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

    int n, p, w, d;
    cin>>n>>p>>w>>d;

    int num = p - n*d;
    int denom = w - d;

    int res = num/denom;
    if(num%denom != 0){
        res++;
    }
    if(res > n){
        cout<<-1;
        return 0;
    }
    res = max(res, 0LL);
    /*cout<<res<<" ";
    int z = p - res*w;
    cout<<z/d<<" "<<(n - res - z/d);*/

    int flag = 0;

    for(int i = 0; i <= d; i++){
        int tmp = res + i;
        if((p - tmp*w) < 0) continue;
        if(((p - tmp*w)%d) == 0){
            int q = ((p - tmp*w)/d);
            if((q + tmp) <= n){
                cout<<tmp<<" "<<q<<" "<<(n - tmp - q)<<endl;
                return 0;
            }
        }
    }
    cout<<-1;

    return 0;
}
