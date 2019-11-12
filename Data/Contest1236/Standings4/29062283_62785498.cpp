#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

int n;
int main(){
	int t,i,j,k,a,b,c,ans;
	cin>>t;
	for(;t;t--){
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		for(;b>=1&&c>=2;ans+=3,b--,c-=2);
		for(;a>=1&&b>=2;ans+=3,a--,b-=2);
		cout<<ans<<endl;
	}

	return 0;
}
