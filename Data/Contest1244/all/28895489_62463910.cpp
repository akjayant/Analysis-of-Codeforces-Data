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

    int t;
    cin>>t;
    while(t--){
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        int c1 = a/c;
        if(a%c != 0)    c1++;
        int c2 = b/d;
        if(b%d != 0)    c2++;
        if((c1 + c2) <= k)  cout<<c1<<" "<<c2<<endl;
        else                cout<<-1<<endl;
    }



    return 0;
}
