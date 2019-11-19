#include <bits/stdc++.h>
#define pp push_back
#define pf pop_front
#define pb pop_back
#define va first
#define vb second
using namespace std;
typedef long long ll;

int n,m,k;
vector<pair<int,int>> v;
vector<deque<int>> r,c;

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		v.pp({x-1,y-1});
	}
	for(int i=0;i<n;i++) r.pp({});
	for(int i=0;i<m;i++) c.pp({});
	for(int i=0;i<k;i++){
		r[v[i].va].pp(v[i].vb);
		c[v[i].vb].pp(v[i].va);
	}
	for(int i=0;i<n;i++) sort(r[i].begin(),r[i].end());
	for(int i=0;i<m;i++) sort(c[i].begin(),c[i].end());
	
	int tr=0,br=n,tc=0,bc=m;
	int dir=1;
	int cnt=0;
	int pr=0,pc=-1;
	while((tr!=br)&&(tc!=bc)){
		switch(dir%4){
			case 1:
				if(!r[pr].empty()){
					if(r[pr].size()!= bc - r[pr].front()){cnt++; break;}
					for(int i=r[pr].front(); i<bc; i++){
						if(c[i].size()!= br - tr){cnt++; break;}
					} if(cnt) break;
					int temp = bc-r[pr].front();
					bc = r[pr].front();
					for(int i=pr;i<br;i++){
						for(int j=0;j<temp;j++) r[i].pb();
					}
				}
				pc = bc-1;
				tr++;
			break;
			case 2:
				if(!c[pc].empty()){
					if(c[pc].size()!= br - c[pc].front()){cnt++; break;}
					for(int i=c[pc].front(); i<br; i++){
						if(r[i].size()!= bc - tc){cnt++; break;}
					} if(cnt) break;
					int temp = br-c[pc].front();
					br = c[pc].front();
					for(int i=pc;i>=tc;i--){
						for(int j=0;j<temp;j++) c[i].pb();
					}
				}
				pr = br-1;
				bc--;
			break;
			case 3:
				if(!r[pr].empty()){
					if(r[pr].size()!= r[pr].back() - tc + 1){cnt++; break;}
					for(int i=r[pr].back(); i>=tc; i--){
						if(c[i].size()!= br - tr){cnt++; break;}
					} if(cnt) break;
					int temp = r[pr].back() - tc + 1;
					tc = r[pr].back()+1;
					for(int i=pr;i>=tr;i--){
						for(int j=0;j<temp;j++) r[i].pf();
					}
				}
				pc = tc;
				br--;
			break;
			case 0:
				if(!c[pc].empty()){
					if(c[pc].size()!= c[pc].back()-tr+1){cnt++; break;}
					for(int i=c[pc].back(); i>=tr; i--){
						if(r[i].size()!= bc - tc){cnt++; break;}
					} if(cnt) break;
					int temp = c[pc].back()-tr+1;
					tr = c[pc].back()+1;
					for(int i=pc;i<bc;i++){
						for(int j=0;j<temp;j++) c[i].pf();
					}
				}
				pr = tr;
				tc++;
			break;
		}
		//cout<<pr<<' '<<pc<<endl;
		if(cnt) break;
		dir++;
	}
	cout<<(cnt?"No":"Yes");
}