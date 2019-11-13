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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int a[N];
int n, m;

int main() {
//    freopen("../../%s/data.in", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        string s,t;
        cin>>n;
        cin>>s>>t;
        char x1,x2,y1,y2;
        int dif=0;
        f(i,0,n-1){
            if(s[i]!=t[i]){
                dif++;
                if(dif==1)x1=s[i],x2=t[i];
                else if(dif==2)y1=s[i],y2=t[i];
            }
        }
        if(dif==0||dif==2&&x1==y1&&x2==y2){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
