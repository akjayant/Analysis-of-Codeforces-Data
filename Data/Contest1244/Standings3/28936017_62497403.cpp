#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
#include<unordered_map>
#include<vector>
typedef long long ll;
using namespace std;
map<int,int>t;
int main(){
	int i,n,a;ll k;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		t[a]++;
	}
	auto L=t.begin(),R=--t.end();
	while(k&&L!=R){
		pair<int,int>l1=make_pair((*L).first,t[(*L).first]);
		L++;
		pair<int,int>l2=make_pair((*L).first,t[(*L).first]);
		L--;
		pair<int,int>r1=make_pair((*R).first,t[(*R).first]);
		R--;
		pair<int,int>r2=make_pair((*R).first,t[(*R).first]);
		R++;
		if(l1.second<r1.second){
			ll d=(1LL*l2.first-l1.first)*l1.second;
			if(k<d)return printf("%d",r1.first-(k/l1.second+l1.first)),0;
			k-=d;
			L++;
			t.erase(l1.first);
			t[l2.first]+=l1.second;
		}else{
			ll d=(1LL*r1.first-r2.first)*r1.second;
			if(k<d)return printf("%d",r1.first-k/r1.second-l1.first),0;
			k-=d;
			R--;
			t.erase(r1.first);
			t[r2.first]+=r1.second;
		}
	}
	printf("0");
	return 0;
}