#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n;
		cin>>n;
		int a, b, c;
		cin>>a>>b>>c;
		
		  string s;
		cin>>s;
		int a2=0;
		int b2=0;
		int c2=0;
		for(int i=0;i<s.size(); i++){
			if(s[i]=='R'){
				a2++;
			}
			if(s[i]=='P'){
				b2++;
			}
			if(s[i]=='S'){
				c2++;
			}
		}
		
		
		
		
		char arr[n];
		for(int i=0; i<n; i++){
			arr[i]='O';
		}
		for(int i=0; i<s.size(); i++){
			if(s[i]=='R'){
				if(b>0){
					arr[i]='P';
					b--;
				}
			}
			if(s[i]=='P'){
				if(c>0){
					arr[i]='S';
					c--;
				}
			}
			if(s[i]=='S'){
				if(a>0){
					arr[i]='R';
					a--;
				}
			}
		}
	
		int i=0;
		while(a>0 && i<n){
			if(arr[i]=='O' && a>0){
				arr[i]='R';
				a--;
				
			}
			i++;
		}
		
		i=0;
		while(b>0 && i<n){
			if(arr[i]=='O' && b>0){
				arr[i]='P';
				b--;
				
			}
			i++;
		}
		i=0;
		while(c>0 && i<n){
			if(arr[i]=='O' && c>0){
				arr[i]='S';
				c--;
				
			}
			i++;
		}
		
		int ans=0;
		for(int i=0; i<n; i++){
			if((s[i]=='P' && arr[i]=='S' ) || (s[i]=='R' && arr[i]=='P') || (s[i]=='S' && arr[i]=='R')){
				ans++;
			}
		}
		
		if(n%2==0){
			if(ans<(n/2)){
				cout<<"NO"<<endl;
				
				continue;
			}
			
		}
		if(n%2==1){
			if(ans<((n/2)+1)){
				cout<<"NO"<<endl;
				continue;
			}
		}
		cout<<"YES"<<endl;
		for(int i=0; i<s.size(); i++){
			cout<<arr[i];
		}
		cout<<endl;
	}
	return 0;
}