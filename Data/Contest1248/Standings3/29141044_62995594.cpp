//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//#include<queue>
//#include<cmath>
//#include<map>
//#include<stack>
//#include<set>
//#include<bitset>
//
//using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//typedef pair<int, int> pii;
//#define pb(x) push_back(x)
//#define cls(x, val) memset(x, val, sizeof(x))
//#define fi first
//#define se second
//#define mp(x, y) make_pair(x, y)
//#define inc(i, l, r) for(int i=l; i<=r; i++)
//const int inf = 0x3f3f3f3f;
//const int maxn = 2000+10;
//int n, m;
//int table[maxn][maxn];
//int tot = 0;
//int dx[4] = {0, -1, 0, 1};
//int dy[4] = {-1, 0, 1, 0};
//
//bool check(int x, int y){
//    if(x<=0||x>n||y<=0||y>m) return false;
//    return true;
//}
//
//
//void dfs(int id){
//    if(id == n*m+1){
//        int b = 0, w = 0;
//        for(int i=1; i<=n; i++){
//            for(int j=1; j<=m; j++){
//                b = w = 0;
//                for(int k=0; k<4; k++){
//                    int nx = dx[k]+i;
//                    int ny = dy[k]+j;
//                    if(check(nx, ny)){
//                        if(table[nx][ny] == 1) b++;
//                        else w++;
//                    }
//                }
//                if(table[i][j]==1&&b>=2) return;
//                if(table[i][j]==2&&w>=2) return;
//            }
//        }
//        tot += 1;
//        return ;
//    }
//    int row, col;
//    if(id%m == 0){
//        row = id/m;
//        col = m;
//    }
//    else {
//        row = id/m+1;
//        col = id%m;
//    }
//    int black = 0, white = 0;
//    for(int i=0; i<2; i++){
//        int nx = dx[i]+row;
//        int ny = dy[i]+col;
//        if(check(nx, ny)){
//            if(table[nx][ny] == 1){
//                black++;
//            }
//            else if(table[nx][ny] == 2)white++;
//        }
//    }
//
//    if(white<=1&&black<=1){
//        table[row][col] = 1;
//        dfs(id+1);
//        table[row][col] = 2;
//        dfs(id+1);
//    }
//    else if(black>=2){
//        table[row][col] = 2;
//        dfs(id+1);
//    }
//    else if(white >=2){
//        table[row][col] = 1;
//        dfs(id+1);
//    }
//}
//
//
//int main(){
//    ios::sync_with_stdio(false);
//    cin>>n>>m;
//    cls(table, -1);
//    dfs(1);
//    cout<<tot<<endl;
//
//    return 0;
//}
//
//


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<bitset>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define pb(x) push_back(x)
#define cls(x, val) memset(x, val, sizeof(x))
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define inc(i, l, r) for(int i=l; i<=r; i++)
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+30;
const int mod = 1e9+7;
ll a[maxn];
ll b[maxn];
int n, m;


int main(){
    ios::sync_with_stdio(false);
    a[1] = 4;
    a[2] = 4;
    for(int i=3; i<=100000+10; i++){
        a[i] = (a[i-1]+a[i-2])%mod;
    }
    b[1] = 2, b[2] = 2;
    for(int i=3; i<200000+20; i++){
        b[i] = (b[i-1]+b[i-2])%mod;
    }
    ll ans = 0;
    cin>>n>>m;
    if(n>m) swap(n, m);
    ans = 2;
    for(int i=2; i<=n; i++){
        ans = (ans+a[i-1])%mod;
    }
    for(int i=n+1; i<=m; i++){
        ans = (ans+b[i-1])%mod;
    }
    cout<<ans<<endl;

    return 0;
}


