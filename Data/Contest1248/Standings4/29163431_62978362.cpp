#include <bits/stdc++.h>

using namespace std ;

#define pb push_back
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define double long double
#define fi first
#define se second
#define INF 1e9
#define N 1005

int main(){
    ios_base :: sync_with_stdio(false);
    int testcase;
    cin >> testcase;
    int x , n , m;
    ll a , b , aa , bb;
    ll ans;
    while(testcase--){
        cin >> n ;
        a = 0 , b = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> x;
            if(x % 2 == 0)
                a++;
            else
                b++;
        }

        cin >> m;
        aa = 0 , bb = 0;

        for(int i = 0 ; i < m ; i++){
            cin >> x;
            if(x % 2 == 0)
                aa++;
            else
                bb++;
        }

        ans = aa * a + bb * b;
        cout << ans << endl;

    }
    return 0;
}
