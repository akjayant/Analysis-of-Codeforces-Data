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
int n;
string s;
int main(){
    fast_io;
    int t; cin >> t;
    while (t--){
        cin >> n >> s;
        int res=n;
        s=' '+s+' ';
        finc(i,1,n) if (s[i]=='1'){
            res=max(res,i*2);
            res=max(res,(n-i+1)*2);
        }
        cout << res << '\n';
    }
    return 0;
}
