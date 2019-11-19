#include<iostream>
#include<cstdio>
using namespace std;
int T,a,b,c,d,k;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d>>k;
		int x=(a-1)/c+1+(b-1)/d+1;
		if(x>k)
			cout<<-1<<endl;
		else
			cout<<(a-1)/c+1<<" "<<(b-1)/d+1<<endl;
	}
	return 0;
}
