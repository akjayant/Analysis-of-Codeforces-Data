#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;

const ll inf=1e18;
const int maxn=1e5+5;
vector<int>g[maxn];
char ch[maxn];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		scanf("%s",ch+1);
		int ac=n;
	 	for(int i=1;i<=n;i++){
	 		if(ch[i]=='1')ac=max(ac,max(n+1,max(i*2,((n-i+1)*2))));
	 	}
	 	printf("%d\n",ac);
	}
	return 0;
} 
 