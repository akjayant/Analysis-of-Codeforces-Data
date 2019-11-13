#include <bits/stdc++.h>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<(int)(y);++i)
#define FORE(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
typedef long long ll;
typedef pair<int,int> pii;
const int INF=2e9;
const int MOD=1e9+7;
const int MAXN=3e2+6;

int ans=0;
int n,m,k,q;
int res[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    int x=n*n;
    FOR(i,0,n){
        FOR(j,0,n){
            res[j][i]=x--;
        }
        ++i;
        FORD(j,n-1,0){
            res[j][i]=x--;
        }
    }
    FOR(i,0,n){
        FOR(j,0,n){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
