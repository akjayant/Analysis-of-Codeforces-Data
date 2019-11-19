#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> ii;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define rep(i,x) for(long long _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(long long _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(long long _b=b,i=a;i>=_b;--i)
#define pb push_back
#define x first
#define y second
#define _ putchar(' ')
#define __ putchar('\n')
using namespace std;
const long long N =   1e6+2;
long long n,k,res;
long long a[N],b[N];
void solve(long long l,long long r){
    if (l>=r) return;
    if (res+r-l<=k){
        res+=r-l;
        swap(b[l],b[r]);
        solve(l+1,r-1);
        return;
    }
    solve(l+1,r);
}
int main(){
    fast_io;
    cin >> n >> k;
    finc(i,1,n) a[i]=b[i]=i;
    finc(i,1,n) res+=i;
    solve(1,n);

    if (res>k){
        cout << -1;
        return 0;
    }

    cout << res << endl;
    finc(i,1,n) cout << a[i] << ' ';
    cout << endl;
    finc(i,1,n) cout << b[i] << ' ';
    return 0;
}
