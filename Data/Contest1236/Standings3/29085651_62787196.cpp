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
    int m;  cin >> m;

    m = (Pow(2,m) + mod - 1) % mod;

    cout << Pow(m,n) << endl;

}