#include "bits/stdc++.h"
#define hhh printf("hhh\n")
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}

const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;

int n, m, k;
vector<int> row[maxn], col[maxn];

int main() {
    cin>>n>>m>>k;
    for(int i=1; i<=k; ++i) {
        int x=read(), y=read();
        row[x].push_back(y);
        col[y].push_back(x);
    }
    for(int i=1; i<=n; ++i) sort(row[i].begin(),row[i].end());
    for(int i=1; i<=m; ++i) sort(col[i].begin(),col[i].end());
    int x=1, y=0, dir=1, ok=1;
    int up=1, lt=0, rt=m+1, dw=n+1;
    ll cnt=0;
    while(ok) {
        ok=0;
        if(dir==1) {
            int ny=rt-1;
            int l=0, r=row[x].size(), m=(l+r)/2;
            while(l<r) {
                if(row[x][m]<=y) l=m+1;
                else r=m;
                m=(l+r)/2;
            }
            if(m!=row[x].size()) ny=min(ny,row[x][m]-1);
            rt=ny;
            if(ny-y) ok=1;
            cnt+=ny-y; y=ny;
            dir=dir%4+1;
        }
        else if(dir==2) {
            int nx=dw-1;
            int l=0, r=col[y].size(), m=(l+r)/2;
            while(l<r) {
                if(col[y][m]<=x) l=m+1;
                else r=m;
                m=(l+r)/2;
            }
            if(m!=col[y].size()) nx=min(nx,col[y][m]-1);
            dw=nx;
            if(nx-x) ok=1;
            cnt+=nx-x; x=nx;
            dir=dir%4+1;
        }
        else if(dir==3) {
            int ny=lt+1;
            int l=0, r=row[x].size(), m=(l+r)/2;
            while(l<r) {
                if(row[x][m]>=y) r=m;
                else l=m+1;
                m=(l+r)/2;
            }
            m--;
            if(m>=0) ny=max(ny,row[x][m]+1);
            lt=ny;
            if(y-ny) ok=1;
            cnt+=y-ny; y=ny;
            dir=dir%4+1;
        }
        else {
            int nx=up+1;
            int l=0, r=col[y].size(), m=(l+r)/2;
            while(l<r) {
                if(col[y][m]>=x) r=m;
                else l=m+1;
                m=(l+r)/2;
            }
            m--;
            if(m>=0) nx=max(nx,col[y][m]+1);
            up=nx;
            if(x-nx) ok=1;
            cnt+=x-nx; x=nx;
            dir=dir%4+1;
        }
    }
    if(cnt+k==1ll*n*m) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}