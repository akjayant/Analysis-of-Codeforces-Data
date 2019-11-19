#include <bits/stdc++.h>

using namespace std;

const long long DIM = 100007;
long long n,m,k,p,res,all,c0,c1,p0,p1,nt;
long long f[DIM], a[107][107];
/*
long long num;
bool ok(int n, int m) {
    num++;
    int flag = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int same = 0;
          //  cout<<a[i][j];
            if(i > 1 && a[i-1][j] == a[i][j]) same++;
            if(i < n && a[i+1][j] == a[i][j]) same++;
            if(j > 1 && a[i][j-1] == a[i][j]) same++;
            if(j < m && a[i][j+1] == a[i][j]) same++;
            if(same > 1) flag = 1;
        }
        //cout<<endl;
    }
    //if(flag == 0) cout<<"OK"<<endl;
    //cout<<endl<<"------------"<<endl;
    return flag == 0;

}

void rec(int r, int c, int val) {
    a[r][c] = val;
    if(r == n && c == m) {
        if(ok(n,m)) res++;
        return;
    }

    if(c == m) {
        rec(r+1,1,0);
        rec(r+1,1,1);
    } else {
        rec(r,c+1,0);
        rec(r,c+1,1);
    }
}
*/

int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;

    long long MODULO = 1000000007;
    if(n > m) swap(n,m);
    f[1] = 2; f[2] = 4;
    for(int i = 3; i <= max(n,m); i++) f[i] = (f[i-1]+f[i-2]) % MODULO;
    res = (f[m]+f[n]-2+MODULO) % MODULO;
    cout<<res<<endl;
    return 0;

/*
    for(n = 1; n <= 4; n++)
        for(m = n; m <= 10; m++) {
            res = 0;
            rec(1,1,0);
            rec(1,1,1);
            cout<<"N="<<n<<' '<<"M="<<m<<' '<<"RES="<<res<<endl;
        }
        */
    return 0;
}
