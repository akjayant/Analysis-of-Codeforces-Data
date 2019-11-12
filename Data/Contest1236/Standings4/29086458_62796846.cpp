#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define FF first
#define SS second
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
typedef pair<int,int> PII;
const int MAX = 2e5 + 5;
int n,cur,flag;
vector<int> vv[555];
int main()
{
	cin>>n; cur=1;
	for(int i = 1; i<=n*n; i++) {
		if(flag == 0) {
			vv[cur].pb(i);cur++;
		}
		if(flag == 1) {
			vv[cur].pb(i);cur--;
		}
		if(cur == n+1) {
			flag = 1;cur=n;
		}
		if(cur == 0) {
			flag = 0;cur=1;
		}
	}
	for(int i = 1; i<=n; i++) {
		for(int j = 0; j<n; j++) {
			printf("%d ",vv[i][j]);
		}
		puts("");
	}

	return 0 ;
}
