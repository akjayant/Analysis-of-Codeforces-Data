#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

int n,k;
string s;
int mini;

int main () {
	
	cin>>n;
	while(n--){
		cin>>k>>s;
		mini=0;
		for(int i=0; i<k; i++){
			if(s[i]=='1'){
				mini=max(mini,max(i+1,k-i));
			}
		}
		if(mini==0){
			cout<<k<<endl;
		}
		else{
			cout<<mini*2<<endl;
		}
	}
	
	return 0;
}
