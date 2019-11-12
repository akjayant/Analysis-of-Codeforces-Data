#include<bits/stdc++.h>
using namespace std;
vector<int> kel[305];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,now=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				now++;
				kel[j].push_back(now);
			}
		}
		else{
			for(int j=n;j>=1;j--){
				now++;
				kel[j].push_back(now);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<kel[i].size();j++){
			if(j<kel[i].size()-1)cout << kel[i][j] << " ";
			else cout << kel[i][j] << '\n';
		}
	}
	return 0;
}


