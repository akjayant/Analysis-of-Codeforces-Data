#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#define fir first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define cl(a,b) memset(a,b,sizeof(a))
#define quickio(a) ios::sync_with_stdio(a)
#define datatest() freopen("data.in","r",stdin)
#define makeans() freopen("data.out","w",stdout)
#define makedata() freopen("data.in","w",stdout)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
const int maxn=500+10;
const int maxm=1e6+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxblock=sqrt(maxn)+10;
const double eps=1e-7;
const ll INF=1e16;
int a[maxn][maxn];
int vis[maxn][maxn];
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for (int j=1;j<=n;j++){
        for (int i=1;i<=n;i++){
            a[i][j]=++cnt;
        }
    }
    for (int i=1;i<=(n+1)/2;i++){
        int l=i,r=(n+1)-i;
        int flag=0;
        for (int j=1;j<=n;j++){
            if (flag) cout<<a[l][j]<<" ";
            else cout<<a[r][j]<<" ";
            flag^=1;
        }
        cout<<endl;
        flag=1;
        if (l==r) continue;
        for (int j=1;j<=n;j++){
            if (flag) cout<<a[l][j]<<" ";
            else cout<<a[r][j]<<" ";
            flag^=1;            
        }
        cout<<endl;
    }
    return 0;
}