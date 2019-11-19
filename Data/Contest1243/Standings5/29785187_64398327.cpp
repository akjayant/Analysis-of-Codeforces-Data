#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

int main()
{
	long long int n;
	cin>>n;

	vector<long long int>v;
	bool f=false;
	for(long long int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			if(n/i==i){
				v.push_back(i);
			}else{
				v.push_back(i);
				v.push_back(n/i);
			}
			f=true;
		}
	}	

	sort(v.begin(),v.end());

	if(!f){
		cout<<n<<endl;
	}else{
		long long int g=-1;
		for(int i=0;i<v.size();i++){
			if(v[i]!=n){
				if(g==-1){
					g=v[i];
				}else{
					g=gcd(g,v[i]);
				}
			}
		}
		cout<<g<<endl;
	}
}