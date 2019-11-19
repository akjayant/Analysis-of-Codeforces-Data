#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
    int n,p,w,d;
    cin >> n >> p >> w >> d;

    if(p%d == 0 && p/d <= n)
    {
        cout << 0 << " " << p/d << " " << n-p/d << endl;
        return 0;
    }

    if(p%w == 0 && p/w <= n)
    {
        cout << p/w << " " << 0 << " " << n-p/w << endl;
        return 0;
    }

    if(p == 0)
    {
        cout << 0 << " " << 0 << " " << n << endl;
        return 0;
    }

    if(p%__gcd(w,d) || p > w*n)
    {
        cout << -1 << endl;
        return 0;
    }

    int cnt = p/w;
    p -= cnt*w;
    int cnt1 = w%d;

    do
    {
        if(p%d == 0 && cnt + p/d <= n)
        {
            cout << cnt << " " << p/d << " " << n-cnt-p/d << endl;
            return 0;
        }

        // int temp = d - p%d;
        // temp = (temp*cnt1)/__gcd(temp,cnt1);
        int temp = 1;

        p += temp*w;
        cnt -= temp;
    }while(cnt > 0);

    cout << -1 << endl;
}