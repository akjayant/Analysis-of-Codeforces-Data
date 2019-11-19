#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define rep(i,x) for(int _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(int _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(int _b=b,i=a;i>=_b;--i)
#define pb push_back
#define x first
#define y second
#define _ putchar(' ')
#define __ putchar('\n')
using namespace std;
int a,b,c,d,k;
int main(){
    fast_io;
    int t; cin >> t;
    while (t--){
        cin >> a >> b >> c >> d >> k;
        int r1=a/c,r2=b/d;
        if (a%c) ++r1;
        if (b%d) ++r2;
        if (r1+r2<=k) cout << r1 << ' ' << r2; else cout << -1;
        cout << '\n';
    }
    return 0;
}
