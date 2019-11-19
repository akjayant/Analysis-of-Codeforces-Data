#include <bits/stdc++.h>
using namespace std;
long long tmp,n,ctt,byk;
bool ya;
int main(){
	cin>>n;
	// k==n;
	tmp=2;
	while(n>1&&tmp*tmp<=n){
		ya=0;
		while(n%tmp==0){
			ctt = tmp;
			n/=tmp;
			ya = 1;
		}
		if(ya)byk++;
		tmp++;
	}
	if(n>1){
		byk++;
		ctt = n;
	}
	// cout<<byk<<endl;
	if(byk==1)cout<<ctt<<endl;
	else cout<<1<<endl;
}