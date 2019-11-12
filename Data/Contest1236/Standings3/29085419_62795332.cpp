#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<string>
#include<vector>
#define mod (1000000007)
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,now=0;
set<int> s[350]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n*n;){
		if(now==0)
		for(int j=1;j<=n;j++,i++){
			s[j].insert(i);
		}
		else
		for(int j=n;j>=1;j--,i++){
			s[j].insert(i);
		}
		now^=1;
	}
	for(int i=1;i<=n;i++){
		for(auto x:s[i]){
			printf("%d ",x);
		}
		puts("");
	}

	return 0;
}