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
    int n; 
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            int x = max(i, n - 1 - i);
            x++;
            ans = max(ans, 2 * x);
        }
    }
    cout << ans << endl;

    }
    


return 0; 
}