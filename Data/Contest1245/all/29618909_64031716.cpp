#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
	vector<double> dp(100,0);
	vector<int> jump(100,-1);
	
	cout << setprecision(10);

	vector<vector<int> > unwrap(10,vector<int>(10,0));
	int counter=0;
	
	for (int i=0;i<10;++i) for (int j=0;j<10;++j) {
		int k=j;
		if (i&1) k=9-j;
		unwrap[i][k]=counter++;
	}
	
	vector<vector<int> > h(10,vector<int>(10,0));
	for (int i=0;i<10;++i) for (int j=0;j<10;++j) {
		cin >> h[i][j];
		if (h[i][j]>0) jump[unwrap[i][j]]=unwrap[i-h[i][j]][j];
	}

	
	dp[0]=0;
	for (int i=1;i<100;++i) {
		int fail=0;
		for (int j=1;j<=6;++j) {
			if (i-j<0) {++fail; continue;}
			if (jump[i-j]!=-1) dp[i]+=min(dp[i-j],dp[jump[i-j]]);
			else dp[i]+=dp[i-j];
		}
		dp[i]=(6+dp[i])/(6-fail);
		//if (jump[i]!=-1) dp[i]=min(dp[i],dp[jump[i]]);
	}
	cout << dp[99] << endl;
}