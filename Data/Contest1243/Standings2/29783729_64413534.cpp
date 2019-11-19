#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin>>n;
	long long raiz = sqrt(n);
	long long x = 2;
	while(x<=raiz){
		if(n%x==0){
			while(n%x==0) n/=x;
			if(n==1){
				cout<<x<<endl;
			}else{
				cout<<1<<endl;
			}
			return 0;
		}
		x++;
	}
	cout<<n<<endl;
}
