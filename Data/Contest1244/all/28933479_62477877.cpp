#include<bits/stdc++.h>
using namespace std;
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
long long n,p,d,w;
long long x,y;
int main(){
    fast_io;
    cin >> n >> p >> w >> d;
    long long mp=p%d;
    long long mw=w%d;
    finc(i,0,d-1){
        if(mp!=(i*mw)%d) continue;
        long long X=p/w;
        X=i+(X/d)*d;
        if(X*w>p) X-=d;
        if(X<0) continue;
        long long Y=(p-X*w)/d;
        if(X+Y>n) continue;
        cout<<X<<" "<<Y<<" "<<n-X-Y;
        return 0;
    }
    cout<<-1;
    return 0;
}
