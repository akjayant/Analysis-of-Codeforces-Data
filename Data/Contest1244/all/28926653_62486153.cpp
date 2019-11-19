#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define sz(x) ((int)x.size())
#define ii pair<int,int>
#define ll long long
#define ppb pop_back
#define N 200005
#define MOD 1000000007
#define inf 2000000000
#define iii pair<pair<int,int>,int>
#define P 1000003
using namespace std;

int n,k;
char s[N];
int dad[N],sz[N];
int vis[N],fu[N],dd[N];

int find(int x) {return dad[x]=(x==dad[x]?x:find(dad[x]));}

void merge(int a,int b) {

	a=find(a);
	b=find(b);

	sz[b]+=sz[a];
	dad[a]=b;

}

int main() {

	scanf("%d %d",&n,&k);

	scanf("%s",s);

	for(int i=0;i<n;i++) dad[i]=i,sz[i]=1;

	for(int i=0;i<n;i++) {

		if(s[i]==s[(i+1)%n]) merge(i,(i+1)%n); 

	}

	deque<iii> q;

	for(int i=0;i<n;i++) {

		if(sz[find(i)]>1) q.push_back({{i,0},s[i]-'A'});

	}

	while(!q.empty()) {

		iii x=q.front();

		q.pop_front();

		int pos=x.st.st;
		int d=x.st.nd;
		int c=x.nd;

		if(vis[pos]) continue ;

		vis[pos]=1;
		dd[pos]=d;
		fu[pos]=c;

		if(find(pos)==find((pos+1)%n)) {

			q.push_front({{(pos+1)%n,d},c});

		}
		else {

			q.push_back({{(pos+1)%n,d+1},c});

		}

		if(find(pos)==find((pos-1+n)%n)) {

			q.push_front({{(pos-1+n)%n,d},c});

		}
		else {

			q.push_back({{(pos-1+n)%n,d+1},c});

		}

	}

	char ss[]="BW";

	for(int i=0;i<n;i++) {

		if(!vis[i]) continue ;

		if(dd[i]<=k) {

			s[i]='A'+fu[i];

		}
		else {

			int p=(ss[0]!=s[i]);

			p+=k&1;
			p&=1;

			s[i]=ss[p];

		}

	}

	printf("%s",s);

}