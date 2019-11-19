#include <bits/stdc++.h>
#define stop system("pause")
#define INP freopen("input.txt","r",stdin)
#define OUTP freopen("output.txt","w",stdout)
#define int long long
using namespace std;

typedef long long ll;

int mod = 1e9+7;
const int maxn = 200000;

int pl(int a,int b){
    return (a+b)%mod;
}
int mn(int a,int b){
    int c = a-b;
    if(c < 0)c+=mod;
    return c;
}
int fib[maxn];


main()
{
    ios_base::sync_with_stdio(0);
    int n,m; cin >> n >> m;
    if(n < m)swap(n,m);
    fib[0] = 2;
    fib[1] = 4;
    fib[2] = 6;
    for(int i(3);i<maxn;i++){
        int a = mn(fib[i-1],fib[i-2]);
        int b = mn(fib[i-2],fib[i-3]);
        fib[i] = pl(fib[i-1],pl(a,b));
    }
    //cout << fib[n-1];
    int ans = fib[n-1];
    if(m == 1){
        cout << ans;
        return 0;
    }else {
        ans = pl(ans,2);
        for(int i(0); i < m-2;i++)ans = pl(ans,fib[i]);
    }
    cout << ans;
    return 0;
}
/*
*/
