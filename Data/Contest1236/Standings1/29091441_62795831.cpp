#include <bits/stdc++.h>
#define pp push_back
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> v;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) v.pp({});
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int p = (i%2)?j:(n-1-j);
			v[p].pp(i*n+j+1);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<v[i][j]<<' ';
		}
		cout<<endl;
	}
}