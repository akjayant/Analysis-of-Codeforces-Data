#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scan(x) scanf("%d",&x)
const int maxn=1e9+10;
const int maxn1=205;
const int inf=0x3f3f3f3f;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=ceil(a*1.0/c);
		int y=ceil(b*1.0/d);
		if(x+y<=k)cout<<x<<" "<<y<<endl;
		else cout<<-1<<endl; 
	}
	return 0;
} 
