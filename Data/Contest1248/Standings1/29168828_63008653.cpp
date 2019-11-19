#include<bits/stdc++.h>
using namespace std;
char s[900000];
int sum,n,m,ans,anx,any,ann,an,summax,another;
int st[900000];
void check(int l,int r){
    sum=0;
    for(int i=l;i<=r;i++){
	if(s[i]=='(') {
	    sum++;
	    st[sum]=i;
	}
	else sum--;
	if(sum==2&&s[i]=='(') an++;
	if(sum==0&&s[i]==')'){
	    if(an+1>ans){
		ans=an+1;
		anx=st[1];
		any=i;
	    }
	    an=0;
	}
    }
}
void work(int l,int r){
    sum=0;ans=-1;anx=1;any=1;
    for(int i=l;i<=r;i++){
	if(s[i]=='(') {
	    sum++;
	    st[sum]=i;
	}
	else sum--;
	if(sum==3&&s[i]=='(') an++;
	//printf("%d %d\n",i,an);
	if(sum==2&&s[i]=='(') another++;
	if(sum==1&&s[i]==')'){
	    if(an>ans){
		ans=an;
		anx=st[2];
		any=i;
	    }
	    an=0;
	}
	if(!sum) ann++;
    }
    ans=ans+ann+1;
    //printf("%d %d %d\n",ann,ans,m);
    check(l,r);
    printf("%d\n",ans);
    printf("%d %d\n",(anx-1)%n+1,(any-1)%n+1);
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    m=0;summax=0;
    for(int i=1;i<=n;i++){
	if(s[i]=='(') sum++;
	else sum--;
	//printf("%d %d\n",i,sum);
	if(sum<summax){
	    summax=sum;
	    m=i;
	}
	s[i+n]=s[i];
    }
    if(sum!=0) return printf("0\n1 1\n"),0;
    work(m+1,m+n);
}
