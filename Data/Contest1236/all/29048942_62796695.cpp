#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int,int>   pii;
typedef vector< pii >  vii;
typedef long long int 	ll;

#define pb push_back
#define fe first
#define se second
#define all(a) (a).begin(),(a).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define scn(n) scanf("%d",&n)
#define prn(n) printf("%d\n",n)
#define scnl(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mset(A, val) memset(A, val, sizeof(A))

const ll mod = 1e9 + 7ll;
const int N = (int)1e5 + 7;

int main(){
	
	fast_io;
	int n;
	cin>>n;
	int mat[n][n];
	int cur=1,i=0,j=0;
	while(cur<=n*n){
		mat[i][j]=cur;
		if(j%2==0) i++;
		else i--;

		if(i==n){
			i--;
			j++;
		}
		else if(i==-1){
			i++;
			j++;
		}
		cur++;
	}
	rep(i,0,n){
		rep(j,0,n)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
