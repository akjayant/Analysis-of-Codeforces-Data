#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k,T;
int main() {
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>a>>b>>c>>d>>k;
		if((a-1)/c+1+(b-1)/d+1<=k)cout<<(a-1)/c+1<<' '<<(b-1)/d+1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
