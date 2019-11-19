#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl){cout<<_rpl<<endl;exit(0);}
int nextint(){int x;scanf("%d",&x);return x;}
ll nextll(){ll x;scanf("%lld",&x);return x;}

int read(){
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+(c-'0');c=getchar();}
	return ret*f;
}

int n;
int ans1,ans2=1,ans3=1;
char s[505],b[505];
int a[505];

int main(){
//	freopen("test.txt","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;++i)if(s[i]=='(')cnt1++;else cnt2++;
	if(cnt1!=cnt2){byebye("0\n1 1\n");}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<n;++k){b[k]=s[k];}
			swap(b[i],b[j]);
			memset(a,0,sizeof(a));
			a[0]=(b[0]==')'?-1:1);
			for(int k=1;k<n;++k){
				a[k]=a[k-1]+(b[k]==')'?-1:1);
			}
			int cnt=1,nowmin=a[0];
			for(int k=1;k<n;++k){
				if(a[k]<nowmin){nowmin=a[k];cnt=1;}
				else if(a[k]==nowmin){cnt++;}
			}
			if(cnt>ans1){ans1=cnt,ans2=i+1,ans3=j+1;}
		}
	} 
	printf("%d\n%d %d\n",ans1,ans2,ans3);
	return 0;
}
