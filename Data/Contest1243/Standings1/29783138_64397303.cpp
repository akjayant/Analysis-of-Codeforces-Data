#include<bits/stdc++.h>
using namespace std;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
const int M=1e9+7;
const int maxn=5e5+5;


 
int main(){
 ios_base::sync_with_stdio(false);
 	
 	ll n;
 	cin>>n;

 	int cnt=0;

 	ll p;

 	for(ll i=2;i*i<=n;i++){
 		if(n%i==0){
 			cnt++;
 			//cout<<"**";
 			if(cnt==1){
 				p=i;
 				//cout<<i<<endl;
 			}
 			while(n%i==0){
 				n=n/i;
 			}
 		}
 	}

 	if(n!=1){
 		cnt++;
 		if(cnt==1)
 			p=n;
 	}

 	if(cnt==1){
 		cout<<p<<endl;
 	}
 	else{
 		cout<<1<<endl;
 	}
 	
 	
	return 0;
}