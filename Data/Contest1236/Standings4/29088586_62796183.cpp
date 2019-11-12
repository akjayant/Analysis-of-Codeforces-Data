#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> vec[n+1];
	int j = 1, dir = 1;
	for(int i=1;i<=(n*n);i++){
		vec[j].push_back(i);
		if(dir == -1 and j == 1 and (i+1) < (n*n)){
			vec[j].push_back(i+1);
			i++;
			dir = 1;
		}
		if(dir == 1 and j == n and (i+1) < (n*n)){
			vec[j].push_back(i+1);
			i++;
			dir = -1;
		}
		if(dir == 1){
			j++;
		}
		else{
			j--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j:vec[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}