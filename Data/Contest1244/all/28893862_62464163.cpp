#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define oo 2000000000
#define inf 1000000000000000LL
#define M 1000000007
typedef long long ll;
using namespace std;
const int N = 305001;

int a,b,c,d,k,t,x,y;

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> k;
        x=a/c+(a%c!=0);
        y=b/d+(b%d!=0);
        if(x+y<=k){
            cout << x << ' ' << y << endl;
        }else cout << -1 << endl;
    }



    return 0;
}
