#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int arr[2000005], tn=0;
ll sosu[1000001];
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);
   ll int N;
   cin>>N;
    for(ll int i=1;i*i<=N;i++){
    	if(N%i==0){
    		arr[++tn] = i;
    		if(i*i!=N) arr[++tn] = N/i;
		}
		sosu[i]=1;
	}
	sosu[1]=0; for(ll int i=1;i<=1000000;i++){
		if(sosu[i]==1){
			for(ll int j=2*i;j<=1000000;j+=i){
				sosu[i]==0;
			}
		}
	}
	ll ss=1;
	for(ll int i=2;i<=tn;i++) if(arr[i]<=1000000) if(sosu[arr[i]]) {ss=arr[i]; break;}
	int tr=1;
	while(1){
		if(ss==1) break;
		if(N%ss==0) N/=ss;
		else{
			tr=0; break;
		}
		if(N==1) break;
	}
	if(ss==1) cout<<N;
	else 
	if(tr) cout<<ss;
	else cout<<1;
}