#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int k,n,a[1005];
int main(){
	cin>>k;
	while(k--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=n;i>=1;--i){
			int sum=0;
			for(int j=1;j<=n;++j)
				if(a[j]>=i) ++sum;
			if(sum>=i){printf("%d\n",i);break;}
		}
	}return 0;
}
