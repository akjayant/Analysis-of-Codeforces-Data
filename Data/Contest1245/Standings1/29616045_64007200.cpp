#include<bits/stdc++.h>

using namespace std;

const int   mod = 1e9 + 7;
const int   N   = 1e5 + 1;

int add(int a,int b)    {
    a += b;
    if (a >= mod)
        a -= mod;
    return  a;
}
int mul(int a,int b)    {
    return  1ll * a * b % mod;
}

int f[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    f[0] = 1;
    f[1] = 1;

    for(int i = 2 ; i < N ; ++i)
        f[i] = add(f[i - 1],f[i - 2]);

    string s;
    cin >> s;   s += '#';

    int ans = 1;
    int cnt = 0;

    char x = '#';

    for(char c : s) {
        if (c == 'm')   return  0 * puts("0");
        if (c == 'w')   return  0 * puts("0");
        if (c != x) {
            if (x == 'u' || x == 'n')
                ans = mul(ans,f[cnt]);
            //cout << cnt << " ";
            cnt = 0;    x = c;
        }
        cnt++;
    }

    cout << ans << endl;
}