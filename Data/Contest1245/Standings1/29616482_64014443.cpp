#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)

bool debug=true;

/*    *************************************
	  * Written in New Computer           *
	  * The following code belongs to     *
	  * XiaoGeNintendo of HellHoleStudios *
	  *************************************
*/
template<typename T1,typename T2>ostream& operator<<(ostream& os,pair<T1,T2> ptt){
	os<<ptt.first<<","<<ptt.second;
	return os;
}
template<typename T>ostream& operator<<(ostream& os,vector<T> vt){
	os<<"{";
	for(int i=0;i<vt.size();i++){
		os<<vt[i]<<" ";
	}
	os<<"}";
	return os;
}

struct Tower{
	ll x,y,c,k,id;
};
int n;
Tower t[2005];

bool cmp(Tower a,Tower b){
	if(a.c!=b.c){
		return a.c<b.c;
	}
}

vector<int> light;
vector<pii> edge;

void solve1(){
	sort(t,t+n,cmp);
	
	ll totcost=0;
	for(int i=0;i<n;i++){
		ll basecost=t[i].c;
		int met=-1;
		
		for(int j=0;j<i;j++){
			ll anocost=1ll*(0ll+abs(t[i].x-t[j].x)+abs(t[i].y-t[j].y))*(t[i].k+t[j].k);
			if(anocost<basecost){
				basecost=anocost;
				met=j;
			}
		}
		
		totcost+=basecost;
		if(met==-1){
			light.push_back(t[i].id);
		}else{
			edge.push_back(make_pair(t[met].id,t[i].id));
		}
	}
	
	cout<<totcost<<endl;
	cout<<light.size()<<endl;
	for(int x:light){
		cout<<x+1<<" ";
	}
	cout<<endl<<edge.size()<<endl;
	for(pii x:edge){
		cout<<x.first+1<<" "<<x.second+1<<endl;
	}
}

bool open[2005];
int cost[2005];
int source[2005];
void refresh(int pos){
	for(int i=0;i<n;i++){
		if(!open[i]){
			ll shit=1ll*(0ll+abs(t[pos].x-t[i].x)+abs(t[pos].y-t[i].y))*(t[pos].k+t[i].k);
			if(shit<cost[i]){
				cost[i]=shit;
				source[i]=pos;
			}
		}
	}
}

void solve2(){
	ll ac=0;
	
	int mn=0;
	for(int i=0;i<n;i++){
		cost[i]=t[i].c;
		source[i]=-1;
		if(cost[i]<cost[mn]){
			mn=i;
		}
	}
	
	light.push_back(mn);
	open[mn]=true;
	refresh(mn);
	
	ac+=cost[mn];
	
	for(int i=0;i<n-1;i++){
		int mn=-1;
		for(int j=0;j<n;j++){
			if(!open[j] && (mn==-1 || cost[j]<cost[mn])){
				mn=j;
			}
		}
		
		ac+=cost[mn];
		open[mn]=true;
		refresh(mn);
		
		if(source[mn]==-1){
			light.push_back(mn);
		}else{
			edge.push_back(make_pair(source[mn],mn));
		}
	}
	
	cout<<ac<<endl;
	cout<<light.size()<<endl;
	for(int x:light){
		cout<<x+1<<" ";
	}
	cout<<endl<<edge.size()<<endl;
	for(pii x:edge){
		cout<<x.first+1<<" "<<x.second+1<<endl;
	}
}

int main(int argc,char* argv[]){
	qi;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i].x>>t[i].y;
		t[i].id=i;
	}
	for(int i=0;i<n;i++){
		cin>>t[i].c;
	}
	for(int i=0;i<n;i++){
		cin>>t[i].k;
	}
	
//	solve1();
	
	solve2();
	
	return 0;
}

