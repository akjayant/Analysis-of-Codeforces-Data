#include<bits/stdc++.h>
using namespace std;
const int MX = 1009;
long double ans[MX];
int T , n;
pair < int , int > arr[MX];
int main(){
   // freopen("exptree.in","r",stdin);
    int T;
    cin>>T;
    while(T--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if (x + y <= k) cout << x << ' ' << y << endl;
        else cout << -1 << endl;
    }
}