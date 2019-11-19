#include <bits/stdc++.h>
#define int long long

using namespace std;

int t[1000];
double r[1000];

int nr(int x, int y) {
    int res = 100;
    res -= 20 * (y/2);
    y %= 2;
    if (y) {
        res -= 20 - x;
    } else
        res -= x + 1;
    return res;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i=0;i<10;i++)
    for (int j=0;j<10;j++)
    {
        int a;
        cin>>a;
        if(a) {
            t[nr(j, i)] = nr(j, i-a);
        }
    }

    for(int i = 99 - 1; i >=0 ; i--)
    {
        for(int j= 1 ;j<=6;j++) {
            if(t[i+j]) {
                r[i] += min(r[i+j], r[t[i+j]]);
            } else
                r[i] += r[i+j];
        }
        r[i] /= 6.0;
        r[i]++;
        r[i] *= 6.0/min(99.0 - i, 6.0);
    }

    cout.precision(10);
    cout<<fixed;
    cout<<r[0]<<endl;


    return 0;
}