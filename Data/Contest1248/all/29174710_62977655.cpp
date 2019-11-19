#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m,w;
long long x,y,s;
int main(){
	scanf("%d",&T);
	while(T--){
		x=y=s=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&w);
			if(w&1) ++y;
			else ++x;
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d",&w);
			if(w&1) s+=y;
			else s+=x;
		}
		cout<<s<<endl;
	}return 0;
}
