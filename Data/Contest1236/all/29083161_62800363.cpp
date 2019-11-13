#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> A;
int main(){
	scanf("%d",&n);
	A.resize(n+1);

	int k = 1;
	for(int i=1;i<=n-1;i++){
		if(i&1) for(int j=1;j<=n;j++) A[j].push_back(k++);
		else for(int j=n;j>=1;j--) A[j].push_back(k++);
	}
	if(n % 2 == 1) for(int j=1;j<=n;j++) A[j].push_back(k++);
	else for(int j=n;j>=1;j--) A[j].push_back(k++);

	for(int i=1;i<=n;i++){
		for(int j: A[i]) printf("%d ",j);
		printf("\n");
	}
	
	return 0;
}

