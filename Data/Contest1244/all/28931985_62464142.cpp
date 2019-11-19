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

int n;


int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        int a,b,c,d,k; cin >> a >> b >> c >> d >> k;

        int x = a / c + 1;
        int y = b / d + 1;

        if(a % c == 0) x--;
        if(b % d == 0) y--;

        if(x + y <= k){
            cout << x << " " << y << "\n";
        }else{
            cout << "-1\n";
        }
    }
}
