#include <bits/stdc++.h>
using namespace std;
long long n, t[1000010], a, b, l, r;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	
	sort(t+1,t+n+1);
	l=1;
	r=n;
	while(l<r){
		a+=t[l];
		b+=t[r];
		l++;
		r--;
	}
	
	if(l==r){
		b+=t[r];
	}
	
	cout<<a*a+b*b<<endl;
}
