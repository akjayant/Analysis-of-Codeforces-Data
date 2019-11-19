#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int tmp=(a-1)/c+(b-1)/d+2;
		if(tmp>k){
			cout<<-1<<'\n';
		}
		else{
			cout<<(a-1)/c+1<<' '<<(b-1)/d+1<<'\n';
		}
	}
	return 0;
}

