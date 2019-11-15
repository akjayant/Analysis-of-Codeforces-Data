#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int>vi;
typedef pair<int,int>pii;
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define dep(i,a,b) for (int i=a;i>=b;i--)
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
const int N=200+10;

int a[400][400];

int main() {
	int n;
	int t=0;
	cin>>n;
	rep(i,1,n) 
	rep(j,1,n) a[i][j]=++t;
	
	rep(i,1,n) {
		int t=i;
		rep(j,1,n) {
			if (j%2==1) {
				printf("%d ",a[j][i]);
			}else printf("%d ",a[j][n-i+1]);
		}
		printf("\n");
	}
	return 0;
} 

