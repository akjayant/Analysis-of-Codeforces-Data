#include<bits/stdc++.h>
using namespace std;
const int N =1e5+9;
const int mod = 1e9+7;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k,x,y;
    cin>>n>>m>>k;
    set<pair<int,int>> s;
    vector<int> sx[n],sy[m];
    for(int i=0;i<k;i++) cin>>x>>y,x--,y--,s.insert({x,y}),sx[x].push_back(y),sy[y].push_back(x);
    for(int i=0;i<n;i++) sort(sx[i].begin(),sx[i].end());
    for(int i=0;i<m;i++) sort(sy[i].begin(),sy[i].end());
    int stx=0,ex=n-1,sty=0,ey=m-1,d=1,i=0,j=0;
    while(1){
    	if(s.find({i,j})!=s.end()) break;
    	if(i>ex||i<stx) break;
    	if(j>ey||j<sty) break;
    	if(d==1){
    		int ub= upper_bound(sx[i].begin(),sx[i].end(),j)-sx[i].begin();
    		if(ub<sx[i].size()&&ub>=0) ub = sx[i][ub]-1;
    		else ub = ey;
    		if(sx[i].size()==0 ||ub<sty ||ub>ey) ub = ey;
    		for(int yy = ub+1;yy<=ey;yy++)
    			for(int xx=stx;xx<=ex;xx++){
    				if(s.find({xx,yy})==s.end()){
    					cout<<"NO";
    					return 0;
					}
				}
			d=2;
			stx++;
			ey = ub;
			j = ey;
			i++;
		}
		else if(d==2){
    		int ub= upper_bound(sy[j].begin(),sy[j].end(),i)-sy[j].begin();
    		if(ub<sy[j].size()&&ub>=0) ub = sy[j][ub]-1;
    		else ub = ex;
    		if(sy[j].size()==0 ||ub<stx ||ub>ex) ub = ex;
    		for(int xx=ub+1;xx<=ex;xx++)
    			for(int yy = sty;yy<=ey;yy++){
    				if(s.find({xx,yy})==s.end()) {
    					cout<<"NO";
    					return 0;
					}
				}
			d=3;
			ey--;
			ex = ub;
			i = ex;
			j--;
		}
		else if(d==3){
			int ub= upper_bound(sx[i].begin(),sx[i].end(),j)-sx[i].begin()-1;
    		if(ub<sx[i].size()&&ub>=0) ub = sx[i][ub]+1;
    		else ub = sty;
    		if(sx[i].size()==0 ||ub<sty ||ub>ey) ub = sty;
    		for(int yy = ub-1;yy>=sty;yy--)
    			for(int xx=stx;xx<=ex;xx++){
    				if(s.find({xx,yy})==s.end()){
    					cout<<"NO";
    					return 0;
					}
				}
			d=4;
			ex--;
			sty = ub;
			j = sty;
			i--;
		}
		else if(d==4){
    		int ub= upper_bound(sy[j].begin(),sy[j].end(),i)-sy[j].begin()-1;
    		if(ub<sy[j].size()&&ub>=0) ub = sy[j][ub]+1;
    		else ub = stx;
    		if(sy[j].size()==0 ||ub<stx ||ub>ex) ub = stx;
    		for(int xx=ub-1;xx>=stx;xx--)
    			for(int yy = sty;yy<=ey;yy++){
    				if(s.find({xx,yy})==s.end()){
    					cout<<"NO";
    					return 0;
					}
				}
			d=1;
			sty++;
			stx = ub;
			i = stx;
			j++;
		}
	}
	for(i=stx;i<=ex;i++)
		for(j=sty;j<=ey;j++)
			if(s.find({i,j})==s.end()){
    					cout<<"NO";
    					return 0;
					}
    cout<<"YES";
	return 0;
}