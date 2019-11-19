#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        int pens = (a+c-1)/c;
        int pencils = (b+d-1)/d;
        if(pens+pencils <= k) cout << pens << " " << pencils << endl;
        else cout << -1 << endl;
    }
}
