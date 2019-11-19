#include<bits/stdc++.h>
using namespace std;


int main(){
	int tc , n;
	string s;
	cin>>tc;
	while(tc--){
		cin>>n>>s;
		int jarak = 0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				jarak = max(jarak , max(i+1 , n-i));
			}
		}
		jarak = max(2*jarak , n);
		cout<<jarak<<endl;
	}
}
