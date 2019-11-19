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
int a[100005];
ll ans1,ans2;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	sort(a,a+n);
	if(n&1){
		ll sum=0,sum2=0;
		for(int i=0;i<n;++i){
			sum+=a[i];
		}
		for(int i=0;i<n/2;++i)sum2+=a[i];
		ans1=sum2*sum2+(sum-sum2)*(sum-sum2);
		sum2+=a[n/2];
		ans2=sum2*sum2+(sum-sum2)*(sum-sum2);
		printf("%lld\n",max(ans1,ans2));
	}
	else{
		ll sum=0,sum2=0;
		for(int i=0;i<n;++i){
			sum+=a[i];
		}
		for(int i=0;i<n/2;++i)sum2+=a[i];
		ans1=sum2*sum2+(sum-sum2)*(sum-sum2);
		printf("%lld\n",ans1);
	}
	return 0;
}
