#include<bits/stdc++.h>
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,k,cnt;
int pre[N],nxt[N];
char s[N],col[N];
set<int>ss1,ss2;
set<int>::iterator it;
int main(){
	//freopen("a.in","r",stdin);
	n=read(),k=read();
	scanf("%s",s+1);
	memset(col,0,sizeof(col));
	for (int i=1;i<=n;++i)
		pre[i]=i-1,nxt[i]=i+1;
	pre[1]=n,nxt[n]=1;
	for (int i=1;i<=n;++i)
		if (s[pre[i]]==s[i] || s[i]==s[nxt[i]])
			col[i]=s[i];
	for (int i=1;i<=n;++i){
		if (!col[i]) ++cnt;
		if (col[i] && (!col[pre[i]] || !col[nxt[i]])) 
			ss1.insert(i),ss2.insert(i);
	}
	int tmp=k;
	if (cnt!=n){
		while (k--){
			if (!cnt) break;
			for (it=ss1.begin();it!=ss1.end();++it){
				ss2.erase(*it);
				if (!col[pre[*it]]) --cnt,col[pre[*it]]=col[*it],ss2.insert(pre[*it]);
				if (!col[nxt[*it]]) --cnt,col[nxt[*it]]=col[*it],ss2.insert(nxt[*it]);
			}
			ss1=ss2;
		}
	}
	for (int i=1;i<=n;++i)
		if (!col[i]){
			if (tmp&1)col[i]=(s[i]=='W')?'B':'W';
			else col[i]=s[i];
		}
	for (int i=1;i<=n;++i)
		putchar(col[i]);
	puts("");
	return 0;
}
