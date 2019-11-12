#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
string str1,str2;
int pos[5];
int cmp(int a,int b){
	return a>b;
}
int qmi(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int qmi1(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int cmp4(int a,int b){
	return a>b;
}
int qmi4(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int qmi12(int a,int b){
	int res=21;
	while(b){
		if(b&1)	res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
int main()
{
    int t; cin>>t;
    while(t--){
        int n; scanf("%d",&n);
        cin>>str1>>str2;
        int cnt=0,k=1;
        int flag=0;
        for(int i=0;i<n;i++){
            if(str1[i]!=str2[i]){
                cnt++;
                pos[k++]=i;
            }
            if(cnt>2){
                flag=1; break;
            }
        }
        
         for(int i=1;i<=0;i++);
         
         for(int i=1;i<=0;i++);
        if(flag) cout<<"No"<<endl;
        else {
            char s1,s2;
            s1=str1[pos[1]];
            s2=str2[pos[2]];
            str1[pos[1]]=s2;
            str2[pos[2]]=s1;
            if(str1==str2) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}