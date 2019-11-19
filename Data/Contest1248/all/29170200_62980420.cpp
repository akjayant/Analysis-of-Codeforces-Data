#include <bits/stdc++.h>
using namespace std;
long long t, m, n, a, b, c, d, pom;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		while(n--){
			cin>>pom;
			if(pom%2==0)
				a++;
			else
				b++;
		}
		cin>>m;
		while(m--){
			cin>>pom;
			if(pom%2==0)
				c++;
			else
				d++;
		}

		cout<<a*c+b*d<<endl;
		a=0;
		b=0;
		c=0;
		d=0;
	}
	

}
