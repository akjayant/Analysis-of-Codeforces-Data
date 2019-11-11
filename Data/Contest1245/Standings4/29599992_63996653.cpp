#include<bits/stdc++.h>
using namespace std;
 
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i)
 
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int mod = 1e9+7;
const int inf = 2e18+5;
const int nax = 101010;
//



signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("fin.txt", "r", stdin);
        freopen("fout.txt", "w", stdout);
    #endif
    //

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int g = __gcd(a, b);
        if(g == 1){
            cout << "Finite\n";
        }else{
            cout << "Infinite\n";
        }
    }



    return 0;
}