#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;



int main () {
	
	int n;
	int a,b,c,d,k;
	cin>>n;
	while(n--){
		cin>>a>>b>>c>>d>>k;
		if((a-1)/c+(b-1)/d+2<=k){
			cout<<(a-1)/c+1<<" "<<(b-1)/d+1<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	
	return 0;
}
