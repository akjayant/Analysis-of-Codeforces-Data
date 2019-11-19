#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N=200005;
#define M 1000000007
#define double long double
#define BINF 100000000000001
#define init(arr,val) memset(arr,val,sizeof(arr))
#define MAXN 15000001
const int LG = 22;




#undef int 
int main() {
#define int long long int
ios_base::sync_with_stdio(false); 
cin.tie(0); 
cout.tie(0);

int t;
cin >> t;
while(t--){
    
    int a, b, x, y , k;
    cin >> a >> b >> x >> y >> k;
    int p = -1, q = -1;
    for(int i = 1; i <= k; i++){
        if(i * x >= a and (k - i) * y >= b){
            p = i, q = k - i;
            break;
        }
    }

    if(p == -1 or q == -1){
        cout << -1 << endl;
    }else cout << p << ' ' << q << endl;

    }
    


return 0; 
}