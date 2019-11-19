#include<bits/stdc++.h>
typedef long long lnt;
const lnt mod = 1e9 + 7;
char a[300100];
int tru(int n){
	int mn=0,tmp=0,rr=0;
	for(int k=0;k<n;k++){
		if(a[k]==')') tmp--;
		else tmp++;
		if(tmp<mn){
			mn=tmp;rr=0;
		}
		if(tmp==mn) rr++;
	}
	return rr;
} 
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",a);
	int le=0,ri=0;
	for(int k=0;k<n;k++){
		if(a[k]=='(') le++;
		else ri++;
	}
	if(le!=ri){
		puts("0\n1 1");
		return 0;
	}
	int mx=0, i1=1, i2=1;
	for(int k=0;k<n;k++){
		for(int i=k;i<n;i++){
			std::swap(a[k],a[i]);
			int re = tru(n);
			if(re>mx){
				mx=re;
				i1=k;i2=i;
			}
			std::swap(a[k],a[i]);
		}
	}
	printf("%d\n%d %d\n",mx,i1+1,i2+1);
}