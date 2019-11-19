#include <bits/stdc++.h>

using namespace std;

const long long DIM = 100007;
long long n,m,k,p,res,all,c0,c1,p0,p1,nt;
long long a[DIM];


int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> nt;
    for(int t = 1; t <= nt; t++) {
        c1 = c0 = p1 = p0 = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >>k;
            if(k % 2 == 0) c0++;
            else c1++;
        }
        cin >> m;
        for(int i = 1; i <= m; i++) {
            cin >>k;
            if(k % 2 == 0) p0++;
            else p1++;
        }
        res = c0*p0 + c1*p1;
        cout<<res<<endl;
    }

    return 0;
}
