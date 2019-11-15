#include<bits/stdc++.h>
using namespace std;

const long long N=200000;

int main(){
	
ios_base::sync_with_stdio(false);


long long t,a,b,c,ans;

cin>>t;

while(t--){
	
	ans=0;
	
	cin>>a>>b>>c;
	
	while((b>0)&&(c>1)){
	ans+=3;
	b--;
	c-=2;}
	
	while((a>0)&&(b>1)){
	ans+=3;
	a--;
	b-=2;}
	
cout<<ans<<endl;}
	
return 0;}