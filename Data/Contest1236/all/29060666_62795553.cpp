#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
int n;
vector<int>ans[300];
int main(){
// 	freopen("input.txt","r",stdin);
	cin >> n;
	int cur = 1;
	while(cur < n*n){
		for(int i = 0;i < n;i++)ans[i].push_back(cur++);
		for(int i = n - 1;i > -1;i--)ans[i].push_back(cur++);
	}
	for(int i = 0;i < n;i++,puts(""))
		for(int j = 0;j < n;j++)
			printf("%d ",ans[i][j]);
}