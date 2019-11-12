#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
 
using namespace std;
 
#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll; 

int n;

void vdeb(vector<int> &da){
	rip(i,n,0){
		if(i==n-1){
			printf("%d\n",da[i]);
		}
		else{
			printf("%d ",da[i]);
		}
	}
}

void vvdeb(vector<vector<int>> &da){
	rip(i,n,0){
		vdeb(da[i]);
	}
}

int main(){
	cin >> n;
	vector<vector<int>> ans(n,vector<int>(n));
	rip(i,n,0){
		if(i%2){
			rip(j,n,0){
				ans[j][i]=i*n+1+j;
			}
		}
		else{
			rip(j,n,0){
				ans[n-j-1][i]=i*n+j+1;
			}
		}
	}
	vvdeb(ans);
}