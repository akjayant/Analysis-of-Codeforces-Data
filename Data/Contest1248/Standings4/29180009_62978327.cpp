#include<iostream>
#define int long long
using namespace std;
signed main(){
	int T;
	cin>>T;
	while(T--){
		int m,n;
		cin>>n;
		int a=0,b=0,c=0,d=0;
		int A;
		while(n--){
			cin>>A;
			if(A%2) a++;
			else b++;
		}
		cin>>m;
		while(m--){
			cin>>A;
			if(A%2) c++;
			else d++;
		}
		cout<<a*c+b*d<<endl;
	}
}