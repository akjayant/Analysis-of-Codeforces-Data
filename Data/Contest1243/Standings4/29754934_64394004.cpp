#include<bits/stdc++.h>
using namespace std;
char s[20202],t[20202],d;
long long n,k,i,j,a,b,c,x,y,z[169],l,u[101],v[101],f=0;
int main(){
	cin>>k;
	for(i=1;i<=k;i++){
		cin>>n>>s>>t;
		c=1;
		for(j=0;j<160;j++) z[j]=0;
		for(j=0;j<n;j++){
			a=s[j];
			b=t[j];
			z[a]++;
			z[b]++;
		}
		for(j=0;j<160;j++) if(z[j]%2==1){
			cout<<"No"<<endl;
			c=-1;
			break;
		}
		if(c>=0) for(j=0;j<n;j++){
			f=1;
			for(l=j+1;l<n;l++) if(s[j]==s[l]){
				u[c]=l+1;
				v[c]=j+1;
				d=s[l];
				s[l]=t[j];
				t[j]=d;
				c++;
				f=0;
				break;
			}
			if(f==1) for(l=j+1;l<n;l++) if(s[j]==t[l]){
				u[c]=n;
				v[c]=l+1;
				c++;
				u[c]=n;
				v[c]=j+1;
				c++;
				d=s[n-1];
				s[n-1]=t[j];
				t[l]=d;
				t[j]=s[j];
				break;
			}
		}
		if(c>=0) cout<<"Yes"<<endl<<c-1<<endl;
		if(c>=0) for(j=1;j<c;j++) cout<<u[j]<<" "<<v[j]<<endl;
	}
}