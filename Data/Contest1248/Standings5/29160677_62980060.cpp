#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> A(n);
		int evena=0,evenb=0,odda=0,oddb=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			if(A[i]%2==0)
				evena++;
			else
				odda++;		
		}
		int m; cin>>m;
		vector<int> B(m);
		for(int i=0;i<m;i++){
			cin>>B[i];	
			if(B[i]%2==0)
				evenb++;
			else
				oddb++;
		}
		long long int ans= (long long)evena*(long long)evenb + (long long)odda*(long long)oddb;
		cout<<ans<<endl;
		
	}
	return 0;
}