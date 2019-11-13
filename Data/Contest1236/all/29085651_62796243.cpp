#include<bits/stdc++.h>

using namespace std;

const int   mod = 1e9 + 7;

int mul(int a,int b)    {
    return  1ll * a * b % mod;
}
int Pow(int a,int b)    {
    int ans = 1;
    while (b)   {
        if(b & 1)   ans = mul(ans,a);
        a = mul(a,a);   b >>= 1;
    }
    return  ans;
}

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;

    if (n % 2 == 0) {
        int l = 1, r = n * n;

        for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)    {
            int u = i * n + j;
            if (u & 1)  cout << l++ << " ";
            else        cout << r-- << " ";
            if (j == n - 1)
                cout << "\n";
        }
    }
    if (n % 2 == 1) {
        int l = 1;
        int r = n * n;
        int c = 0;
        for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= n ; ++j)   {
            if (j == n) {
                cout << n * (n - 1) / 2 + i << "\n";
                continue;
            }
            if (c)  cout << l++ << " ";
            else    cout << r-- << " ";
            c ^= 1;
        }
    }
}