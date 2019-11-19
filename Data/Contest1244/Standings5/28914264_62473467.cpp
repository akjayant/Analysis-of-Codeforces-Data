#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int menor=n;
		int maior=0;
		int cont=0;
		for (int i=0; i<n; i++){
			if (s[i]=='1'){
				cont++;
				maior=i+1;
				if (menor==n) menor=i;
			}
			
		}
		//cout<<menor<<" "<<maior<<endl;
		int res=max((n-menor)*2,maior*2);
		//cout<<res<<endl;
		cout<<max(res,n+cont)<<endl;
	
	}

}
