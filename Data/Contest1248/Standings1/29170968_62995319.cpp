#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
int n,f[1100],q[1100],he,ta,te,ans,a1,a2;
char s[1100],a[550];
int main(){
	scanf("%d%s",&n,a+1);
	te=0;
	fo(i,1,n) s[i]=a[i];
	fo(i,1,n-1) s[i+n]=s[i];
	fo(i,1,n+n-1){
		f[i]=f[i-1];
		if (s[i]=='(') f[i]++;else f[i]--;
	}
	he=1;ta=0;
	fo(i,1,n+n-1){
		while (he<=ta&&f[i]<f[q[ta]]) ta--;
		q[++ta]=i;
		if (i>=n){
			if (q[he]<i-n+1) he++;
			if (f[i]==f[i-n]&&f[q[he]]>=f[i-n]) te++;
		}
	}
	ans=te;
	a1=1;
	a2=1;
	fo(t1,1,n)
		fo(t2,t1,n)
			if (a[t1]!=a[t2]){
				te=0;
				fo(i,1,n) s[i]=a[i];
				s[t1]=a[t2];
				s[t2]=a[t1];
				fo(i,1,n-1) s[i+n]=s[i];
				fo(i,1,n+n-1){
					f[i]=f[i-1];
					if (s[i]=='(') f[i]++;else f[i]--;
				}
				he=1;ta=0;
				fo(i,1,n+n-1){
					while (he<=ta&&f[i]<f[q[ta]]) ta--;
					q[++ta]=i;
					if (i>=n){
						if (q[he]<i-n+1) he++;
						if (f[i]==f[i-n]&&f[q[he]]>=f[i-n]) te++;
					}
				}
				if (te>ans){
					ans=te;
					a1=t1;
					a2=t2;
				}
			}
	printf("%d\n%d %d\n",ans,a1,a2);
	return 0;
}