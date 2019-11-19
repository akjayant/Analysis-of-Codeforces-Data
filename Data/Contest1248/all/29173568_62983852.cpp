#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =1e5+ 7;
int n,sum1,sum2;
int a[N];
template<class T> inline void read(T &x) {
    bool f = false; x = 0;
    char ch = getchar();
    while (ch<'0' || ch>'9') {if (ch == '-') f = true; ch = getchar();}
    while (ch>='0' && ch<='9') x = x * 10 + ch - '0', ch = getchar();
    if (f) x = -x;
}
signed main() {
    read(n);
    for (int i = 1 ;i <= n;i++) {
        read(a[i]);
    }
    sort(a+ 1,a +1 +n);
    int sum1 =0,sum2=0;
    if (n % 2 ==0) {
        for (int i =1; i<= n /2; i++) {
            sum1+=a[i];
        }
        for (int i =n/2+1;i <=n;i++) {
            sum2+=a[i];
        }
    } else {
        for (int i =1; i<= n /2; i++) {
            sum1+=a[i];
        }
        for (int i =n/2+1;i <=n-1;i++) {
            sum2+=a[i];
        }
        sum2+=a[n];
    }
    cout<<sum1*sum1+sum2*sum2<<endl;
    return 0;
}