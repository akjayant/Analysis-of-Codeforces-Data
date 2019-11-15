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
 	
 	int t;
 	cin>>t;

 	while(t--){
 		int n;
 		cin>>n;

 		string s1,s2;
 		cin>>s1>>s2;

 		int cnt=0;

 		int fi,si;

 		for(int i=0;i<n;i++){
 			if(s1[i]!=s2[i]){
 				cnt++;
 				if(cnt==1){
 					fi=i;
 				}
	 			else if(cnt==2){
	 				si=i;
	 			}
	 			else{
	 				break;
	 			}
 			}
 			
 		}
 		//cout<<cnt<<endl;
 		if(cnt!=2){
 			cout<<"No"<<endl;
 		}
 		else{
 			//cout<<fi<<" "<<si<<endl;
 			if(s1[fi]==s1[si] && s2[fi]==s2[si]){
 				cout<<"Yes"<<endl;
 			}
 			else{
 				cout<<"No"<<endl;
 			}
 		}
 	}
 	
 	
	return 0;
}