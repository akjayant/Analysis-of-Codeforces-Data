
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//INF = 1 061 109 567 ; INF + INF = 2 122 219 134 ;
//LINF = 4 557 430 888 798 830 399 ; LINF + LINF = 9 114 861 777 597 660 798 ;
const int INF = 0x3f3f3f3f;     // -INF: 0xc0   abs(-INF) = INF + 1
const ll LINF = 0x3f3f3f3f3f3f3f3f;
/*}}}*/                         // zr, zm
const int MOD = (int)1e9+7;     // when MOD = 1e9+7, inv2 = 500000004
const int N = (int)1e6+7;
const int M = (int)-1;

int a[400][400];
int main()
{
	int n;cin>>n;
	for(int i = 1,j = 1,c = 1;c <= n*n;c++) {
		a[i][j] = c;
		if(j & 1) {
			if(i < n) i++;
			else j++;
		}else {
			if(i > 1) i--;
			else j++;
		}
	}
	rep(i,1,n+1) {
		rep(j,1,n+1) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
