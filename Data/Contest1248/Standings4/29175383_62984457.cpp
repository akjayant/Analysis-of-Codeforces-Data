#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int SIZE=1e5+50;
int a[SIZE],b[SIZE];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int cnt=0;
		int aa;scanf("%d",&aa);
		int ji1=0,ji2=0,ou1=0,ou2=0;
		for(int i=1;i<=aa;i++){
			scanf("%d",&a[i]);
			if(a[i]&1)ji1++;
			else ou1++;
		}
		int bb;scanf("%d",&bb);	
		for(int i=1;i<=bb;i++){
			scanf("%d",&b[i]);
			if(b[i]&1)ji2++;
			else ou2++;
		}
		printf("%lld",(ll)ji1*(ll)ji2+(ll)ou1*(ll)ou2);
		if(t)printf("\n");
	}
}