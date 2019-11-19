#include <bits/stdc++.h>
#define for_(i,a,b) for(int i=a;i<b;++i)
#define for__(i,a,b) for(int i=a;i<=b;++i)
#define rof_(i,a,b) for(int i=a;i>b;--i)
#define rof__(i,a,b) for(int i=a;i>=b;--i)
#define ms(a,b) memset((a),(b),sizeof((a)))

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int MN = 1e5 + 5;
const int P = 998244353;

const int R=1, D=2, L=3, U=4;
vector<int>sr[MN],sc[MN];

inline void solve(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	ll sm=ll(n)*m-k-1;
	for__(i,1,n) sr[i].push_back(0);
	for__(i,1,m) sc[i].push_back(0);
	for_(i,0,k){
		int x,y; scanf("%d%d",&x,&y);
		sr[x].push_back(y), sc[y].push_back(x);
	}
	for__(i,1,n) sr[i].push_back(m+1);
	for__(i,1,m) sc[i].push_back(n+1);
	for__(i,1,n) sort(sr[i].begin(),sr[i].end());
	for__(i,1,n) sort(sc[i].begin(),sc[i].end());
	int nowx=1, nowy=1, dir=1;
	int rl=0, cl=0, rr=n+1, cr=m+1;
	if(sr[1][1]==2){
		return puts(sc[1][1]-2==sm? "YES": "NO"),void();
	}
	for_(i,0,n+m){
//cout<<nowx<<' '<<nowy<<'\n';
		int ed, lstx=nowx, lsty=nowy;
		if(dir==R){
			ed=min(cr,*lower_bound(sr[nowx].begin(),sr[nowx].end(),nowy));
			sm-=ed-nowy-1;
			nowy=ed-1;
			cr=nowy;
			rl=nowx;
		}else if(dir==D){
			ed=min(rr,*lower_bound(sc[nowy].begin(),sc[nowy].end(),nowx));
			sm-=ed-nowx-1;
			nowx=ed-1;
			cr=nowy;
			rr=nowx;
		}else if(dir==L){
			auto it=lower_bound(sr[nowx].begin(),sr[nowx].end(),nowy);
			--it;
			ed=max(cl,*it);
			sm-=nowy-ed-1;
			nowy=ed+1;
			cl=nowy;
			rr=nowx;
		}else if(dir==U){
			auto it=lower_bound(sc[nowy].begin(),sc[nowy].end(),nowx);
			--it;
			ed=max(rl,*it);
			sm-=nowx-ed-1;
			nowx=ed+1;
			cl=nowy;
			rl=nowx;
		}
		if(lstx==nowx && lsty==nowy) break;
		++dir;
		if(dir>4) dir=1;
	}
	puts(sm? "NO": "YES");
}

int main(int argc, char** argv){
//	ios::sync_with_stdio(0);
//	int _; scanf("%d",&_); for_(i,0,_)
		solve();
	
	return 0;
}

