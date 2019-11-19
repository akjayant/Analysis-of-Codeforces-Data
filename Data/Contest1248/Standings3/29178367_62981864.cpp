#include <bits/stdc++.h>

using namespace std;

const long long DIM = 100007;
long long n,m,k,p,res,all,c0,c1,p0,p1,nt;
long long a[DIM];


int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; i++) {
        if(i <= n/2) c1+= a[i];
        else c0+=a[i];
    }
    res = c1*c1+c0*c0;
    cout<<res<<endl;

    return 0;
}
