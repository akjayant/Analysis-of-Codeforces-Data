#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl){cout<<_rpl<<endl;exit(0);}
int nextint(){int x;scanf("%d",&x);return x;}
ll nextll(){ll x;scanf("%lld",&x);return x;}
template<class T>T emax(T& t1,T t2){if(t1<t2)t1=t2;return t1;}
template<class T>T emin(T& t1,T t2){if(t1>t2)t1=t2;return t1;}

int read(){
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+(c-'0');c=getchar();}
	return ret*f;
}

int n;
ll d[2005],ans;
int last_mod[2005];
vector<int> st;
vector<pii> con;

struct city{
	ll x,y;
	ll c,k;
	int id;
	bool used;
	bool operator<(const city& c2)const{
		if(c!=c2.c)return c<c2.c;
		return id<c2.id;
	}
}a[2005];

ll calc_cost(int id1,int id2){
	ll dis=abs(a[id1].x-a[id2].x)+abs(a[id1].y-a[id2].y);
	ll cost=a[id1].k+a[id2].k;
	return cost*dis;
}

int main(){
	memset(last_mod,-1,sizeof(last_mod));
	n=read();
	for(int i=0;i<n;++i){
		a[i].x=read();
		a[i].y=read();
		a[i].id=i;
		a[i].used=false;
	}
	for(int i=0;i<n;++i){
		a[i].c=read();
	}
	for(int i=0;i<n;++i){
		a[i].k=read();
	}
	sort(a,a+n);
	for(int i=0;i<n;++i)d[i]=a[i].c;
	a[0].used=true;
	ans=a[0].c;
	st.push_back(a[0].id);
	int now=0;
	for(int i=1;i<n;++i){
		for(int j=0;j<n;++j){
			ll tmp=calc_cost(now,j);
			if(d[j]>tmp){
				last_mod[j]=now;
				d[j]=tmp;
			}
		}
		int mini=-1;
		for(int j=0;j<n;++j){
			if(a[j].used)continue;
			if(mini==-1){
				mini=j;
				continue;
			}
			if(d[mini]>d[j])mini=j;
		}
		now=mini;
		a[now].used=true;
		ans+=d[now];
		if(last_mod[now]==-1)st.push_back(a[now].id);
		else con.push_back(pii(a[now].id,a[last_mod[now]].id));
	}
	printf("%lld\n",ans);
	printf("%d\n",st.size());
	for(int i=0;i<st.size();++i){
		printf("%d%c",st[i]+1,(i+1==st.size()?'\n':' '));
	}
	printf("%d\n",con.size());
	for(int i=0;i<con.size();++i){
		printf("%d %d\n",con[i].first+1,con[i].second+1);
	}
	return 0;
}
