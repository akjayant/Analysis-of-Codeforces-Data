#include<bits/stdc++.h>
using namespace std;

const long long N=200000,mod=1e9+7;

 long long modular_exponentiation(long long a,long long b,long long c){
	
    long long res=1,exp=a%c;
 
    if(b==0)
    return 1;
 
    while(b!=0){
    if(b%2)
    res=((res)%c*(exp)%c)%c;
    exp=((exp)%c*(exp)%c)%c;
    b=b/2;}
 
    return res%c;}
	

int main(){
	
ios_base::sync_with_stdio(false);

long long t,n,m,ans;

t=1;


while(t--){
	
	cin>>n>>m;
	
	ans=modular_exponentiation((modular_exponentiation(2,m,mod)-1),n,mod)%mod;
	
cout<<ans<<endl;}

return 0;}