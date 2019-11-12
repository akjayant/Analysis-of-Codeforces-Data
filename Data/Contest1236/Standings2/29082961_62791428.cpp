#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define de(x) cout<<#x<<" = "<<x<<"\n"
#define dd(x) cout<<#x<<" = "<<x<<" "
#define mes(p) memset(p,0,sizeof(p))
#define all(x) x.begin(),x.end()
#define rson mid+1,r,rt<<1|1
#define sz(x) (int)x.size()
#define mp make_pair 
#define lson l,mid,rt<<1
#define pb push_back
#define ls (rt<<1)
#define rs (ls|1)
#define se second
#define fi first
typedef pair <int ,int > pi;
typedef vector <int > vi;
const int maxn=4e5+5;
const int mod = 1e9+7;
typedef long long ll;
int a[505][505];
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	int cnt =0;
	rep(i,0,n){
		if(i&1) rep(j,0,n) a[j][i] = ++cnt;
		else for(int j=n-1;j>=0;j--) a[j][i] = ++cnt; 
	}
	rep(i,0,n){
		rep(j,0,n){
			if(j) cout << " ";
			cout << a[i][j];
		}
		cout << "\n";
	} 
	return 0;
}
