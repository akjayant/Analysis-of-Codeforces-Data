#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int flag=0,x=-1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			x=i;
			flag++;
			while(n%i==0)
				n/=i;
			if(n==1)
				flag++;
			break;
		}
	}
	if(x==-1)
		x=n;
	if(flag%2)
		x=1;
	cout << x << endl;
}