#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004
#define INF 1e9+7

using namespace std;

ll t,a,b,c,d,k;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c >> d >> k;

        ll pens = a/c + (ll)(a%c != 0);
        ll pencils = b/d + (ll)(b%d != 0);

        if(pens+pencils > k)
            cout << -1 << "\n";
        else
            cout << pens << " " << pencils << "\n";
    }

    return 0;
}

