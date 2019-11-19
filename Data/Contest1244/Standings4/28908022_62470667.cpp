#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scan(x) scanf("%d",&x)
const int maxn=1e9+10;
const int maxn1=205;
const int inf=0x3f3f3f3f;
string s1;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>s1;
		int lens=s1.size();
		int index1=-1,index2=-1;
		for(int i=0;i<lens;i++){
			if(s1[i]=='1'){
				index1=i;
				break;
			}
		}
		for(int i=lens-1;i>=0;i--){
			if(s1[i]=='1'){
				index2=i;
				break;
			}
		}
		if(index1==-1)cout<<n<<endl;
		else{
			int temp=0;
			temp=max(index1+1,n-index1);
			int temp1;
			temp1=max(index2+1,n-index2);
			temp=max(temp,temp1);
			cout<<temp*2<<endl;
		}
	}
	return 0;
} 
