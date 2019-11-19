#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5 +7;
int n,m,t;
int a[N],b[N];
template<class T> inline void read(T &x) {
    bool f = false; x = 0;
    char ch = getchar();
    while (ch<'0' || ch>'9') {if (ch == '-') f = true; ch = getchar();}
    while (ch>='0' && ch<='9') x = x * 10 + ch - '0', ch = getchar();
    if (f) x = -x;
}
signed main() {
    read(t);
    while (t--) {
        read(n);
        int ca1 = 0, ca2 = 0;
        for (int i = 1 ; i <= n; i++) {
            read(a[i]);
            if (a[i] & 1) ca1++;
            else ca2++;
        }
        read(m);
        int cb1 = 0, cb2=0;
        for (int i =1 ; i<=m; i++) {
            read(b[i]);
            if (b[i] & 1) cb1 ++;
            else cb2++;
        }
        int ans= ca1*cb1+ca2*cb2;
        cout<<ans<<endl;
    }
    return 0;
}