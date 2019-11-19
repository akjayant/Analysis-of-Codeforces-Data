#include <bits/stdc++.h>
#define N 100005
#define task "t"
#define mu(x) x*x
#define sz size

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using piii=pair<int,pii>;
const int inf=1e9+7;

ll a[10][10],n,m,res=0,f[N];

void check()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            int dem=0;
            if (a[i-1][j]==a[i][j]) dem++;
            if (a[i+1][j]==a[i][j]) dem++;
            if (a[i][j+1]==a[i][j]) dem++;
            if (a[i][j-1]==a[i][j]) dem++;
            if (dem>1) return;
        }
/*for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";*/
    res++;
}

void qlui(int i,int j)
{
    if (i>n || i<1 || j>m || j<1) return;
    if (i==n && j==m) {
        a[i][j]=0;
        check();
        a[i][j]=1;
        check();
        return;
    }
    for (int x=0;x<=1;x++) {
        a[i][j]=x;
        if (j==m) qlui(i+1,1);
        else qlui(i,j+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    #ifndef ONLINE_JUDGE
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif // ONLINE_JUDGE
    cin>>n>>m;
    f[1]=2;f[2]=4;
    for (int i=3;i<=max(m,n);i++) f[i]=(f[i-1]+f[i-2])%inf;
    res=1;
    for (int i=1;i<=n;i++) res=(res*2)%inf;
    cout<<(f[n]+(f[m]-2)+inf)%inf;
    return 0;
}
