#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1LL;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
main(){
    fastio;
    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans[n][n];
        int c=n*n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n && (i%2)==0;j++){
                ans[j][i] = c--;
            }
            for(int j=n-1;j>=0 && i%2;j--){
                ans[j][i] = c--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    
}