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

int l[13][13];

const double SIX=1/6.0;
const double TOTAL=6;

inline pii getNext(int x,int y){
	
	if(x%2==1){
		if(y==9){
			return make_pair(x-1,y);
		}
		return make_pair(x,y+1);
	}else{
		if(y==0){
			return make_pair(x-1,y);
		}
		return make_pair(x,y-1);
	}
}

double dp[15][15];

int stk=0;

double dfs(int x,int y){
//	cout<<x<<" "<<y<<endl;
	
	//roll some shit
	if(x==0 && y==0){
		return 0;
	}
	
	if(dp[x][y]>=0){
		return dp[x][y];
	}
	
	stk++;
	if(stk>=50000){
		stk--;
		return 0;
	}
	
	if(x==0 && y<=6){
		double xw=0;
		for(int i=1;i<=6;i++){
			if(y>=i){
				xw+=SIX*(dfs(x,y-i)+1);
			}else{
				xw+=SIX*(dfs(x,y)+1);
			}
		}
		stk--;
		return dp[x][y]=xw;
	}
	
	pii nxt=getNext(x,y);
	double prob=0;
	for(int i=1;i<=6;i++){
		double v;
		if(l[nxt.first][nxt.second]!=0){
			v=min(dfs(nxt.first,nxt.second),dfs(nxt.first-l[nxt.first][nxt.second],nxt.second));
		}else{
			v=dfs(nxt.first,nxt.second);
		}
		prob+=SIX*(v+1);
		nxt=getNext(nxt.first,nxt.second);
	}
	
//	cout<<x<<' '<<y<<" ="<<prob<<endl;
	stk--;
	return dp[x][y]=prob;
}

int main(int argc,char* argv[]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin>>l[i][j];
			dp[i][j]=-1;
		}
	}
	
	printf("%.010f",dfs(9,0));
	return 0;
}

