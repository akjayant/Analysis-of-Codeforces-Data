#include <iostream>
using namespace std;
int n;
int ans[305][305];

int main()

{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++)
				ans[j][i]=(i-1)*n+j;
		}
		else{
			for (int j=n;j>=1;j--)
				ans[j][i]=(i-1)*n+(n-j+1);
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}