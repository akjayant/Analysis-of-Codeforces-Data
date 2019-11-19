#include<bits/stdc++.h>
typedef long long lnt;
const lnt mod = 1e9 + 7;
char a[300100];
int seg[300100];
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
	int mn=0,tmp=0,rr=0;
	for(int k=0;k<n;k++){
		if(a[k]==')') tmp--;
		else tmp++;
		if(tmp<mn){
			mn=tmp;rr=0;
		}
		if(tmp==mn) rr++;
		seg[k]=tmp;
	}
	int mx=rr, i1=0, i2=0;
	//Case mn -1 
	int now=0;
	while(now<n) {
		int t1=-1,t2=-1,to=0;
		for(int k=now;k<n;k++){
			if(a[k]=='(' && t1==-1){
				t1=k;
			}
			if(a[k]==')'){
				t2=k;
			}
			if(t1!=-1 && seg[k]==mn+1){
				to++;
			}
			if(seg[k]==mn || k==n-1){
				now=k+1;
				break;
			}
		}
		if(seg[t2]==mn+1){
			to--;
		}
		if(t1!=-1&&t2!=-1&&t1<t2){
			if(to>mx){
				mx=to;
				i1=t1;i2=t2;
			}
		}
	}
	//case mn
	now=0;
	while(now<n) {
		int t1=-1,t2=-1,to=rr;
		for(int k=now;k<n;k++){
			if(a[k]=='(' && t1==-1){
				t1=k;
			}
			if(a[k]==')'){
				t2=k;
			}
			if(t1!=-1 && seg[k]==mn+2){
				to++;
			}
			if(seg[k]==mn || seg[k]==mn + 1 || k==n-1){
				now=k+1;
				break;
			}
		}
		if(seg[t2]==mn){
			to--;
		}
		if(t1!=-1&&t2!=-1&&t1<t2){
			if(to>mx){
				mx=to;
				i1=t1;i2=t2;
			}
		}
	}
	//case mn + 1
	int x1,x2,qq;
	for(int k=n-1;k>=0;k--){
		if(seg[k]==mn){
			x2=k+1;break;
		}
	}
	for(int k=0;k<n;k++){
		if(a[k]==')'){
			x1=k;
		}
		if(seg[k]==mn) break;
	}
	std::swap(a[x1],a[x2]);
	qq=tru(n);
	std::swap(a[x1],a[x2]);
	if(qq>mx){
		mx=qq;
		i1=x1,i2=x2;
	}
	//case mn + 2
	for(int k=n-1;k>=0;k--){
		if(seg[k]==mn+1){
			x2=k+1;break;
		}
	}
	for(int k=0;k<n;k++){
		if(a[k]==')'){
			x1=k;
		}
		if(seg[k]==mn+1) break;
	}
	std::swap(a[x1],a[x2]);
	qq=tru(n);
	std::swap(a[x1],a[x2]);
	if(qq>mx){
		mx=qq;
		i1=x1,i2=x2;
	}
	
	
	printf("%d\n%d %d\n",mx,i1+1,i2+1);
}