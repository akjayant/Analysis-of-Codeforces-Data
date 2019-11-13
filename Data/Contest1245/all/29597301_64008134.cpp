#include <bits/stdc++.h>
#define int long long

using namespace std;

int fib[1000000];
int mod = 1000000007;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    cin>>a;

    fib[0] = 1;
    fib[1] = 1;
    for(int i=2;i<1000000;i++)
        fib[i] = (fib[i-1] +fib[i-2]) % mod;

                int n = 0;
    int u = 0;
    int res = 1;
    for(int i=0;i<a.size();i++) {
        if(a[i] == 'n')
            n++;
        else {
            res *= fib[n];
            res %= mod;
            n = 0;
        }

        if(a[i] == 'u')
            u++;
        else {
            res *= fib[u];
            res %= mod;
            u = 0;
        }

        if(a[i] == 'm' || a[i] == 'w')
        {
            cout<<0<<endl;
            return 0;

        }

    }

    res *= fib[n];
    res %= mod;

    res *= fib[u];
    res %= mod;

    cout<<res<<endl;

    return 0;
}