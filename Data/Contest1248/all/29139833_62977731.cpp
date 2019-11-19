#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
int N,M;
int cnt[2];
int main(){
	//freopen("in","r",stdin);
	for(int _=read();_;_--){
		N=read();
		cnt[0]=cnt[1]=0;
		long long ans=0;
		for(int i=1;i<=N;i++)
			if(read()&1)
				cnt[1]++;
			else
				cnt[0]++;
		M=read();
		for(int i=1;i<=M;i++)
			if(read()&1)
				ans+=cnt[1];
			else
				ans+=cnt[0];
		cout<<ans<<endl;
	}
	return 0;
}
