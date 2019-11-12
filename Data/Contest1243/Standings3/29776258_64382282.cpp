#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int k;
	cin>>k;
	while(k--){
		int n;
		string s,t;
		cin>>n;
		cin>>s>>t;
		int mismatch = 0;
		char s1, s2, t1, t2 ;
		
		for(int i=0;i<n;i++){
			if(s[i]==t[i]){
				continue;
			}
			else{
				mismatch++;
				if(mismatch>2){
					break;
				}
				else if(mismatch==1){
					s1 = s[i];
					t1 = t[i];
				}
				else if(mismatch==2){
					s2 = s[i];
					t2 = t[i];
				}
			}
		}
		
		if(mismatch>2 || mismatch==1){
			cout<<"No"<<endl;
			continue;
		}
		
		if(s1==s2 && t1==t2){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		
		
	}
	return 0;
}