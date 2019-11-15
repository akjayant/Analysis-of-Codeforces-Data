#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
#define f(i, a, b) for(int i=(a);i<=(b);++i)
#define rf(i, a, b) for(int i=(a);i>=(b);--i)
#define Cl(a) memset(a,0,sizeof(a))
#define Cln(a) memset(a,0xff,sizeof(a))
#define cp(a, b) memcpy(a,b,sizeof(b))
#define sz(a) ((int)((a).size()))
#define pb emplace_back
#define sqr(x) ((x)*(x))
#define all(a) (a).begin(),(a).end()
#define mpr make_pair
#define x first
#define y second
#define Debug(a) cout<<"---"<<a<<"---"<<endl;
#define endl '\n'

using namespace std;
const int INF = ~(1 << 31);
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int a[N];
int n, m;

int main() {
//    freopen("../../%s/data.in", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        int ma=0;
        f(i,1,n)cin>>a[i];
        sort(a+1,a+n+1);
        f(i,1,n){
            int x=lower_bound(a+1,a+n+1,i)-a;
            x=n-x+1;
            if(i<=x)ma=max(ma,i);
        }
        cout<<ma<<endl;
    }
    return 0;
}
