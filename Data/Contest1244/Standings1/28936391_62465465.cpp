#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b,c,d,K;
		cin>>a>>b>>c>>d>>K;
		int fl=0,A,B;
		for(int i=0;i<=K;i++)
			if(i*c>=a&&(K-i)*d>=b){
				fl=1;
				A=i,B=K-i;
			}
		if(fl)cout<<A<<' '<<B<<endl;
		else puts("-1");
	}
	return 0;
}