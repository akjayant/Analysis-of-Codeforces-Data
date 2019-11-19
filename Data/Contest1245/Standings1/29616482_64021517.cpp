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

int t;


int l,r;
inline bool check(bool a,bool b,bool al,bool ar,bool bl,bool br,bool least,bool most){
	if(al && a<least){
		return false;
	}
	if(ar && a>most){
		return false;
	}
	if(bl && b<least){
		return false;
	}
	if(br && b>most){
		return false;
	}
	return true;
}

ll dp[35][2][2][2][2];

ll dfs(int pos,bool al, bool ar,bool bl,bool br){
	if(pos==-1){
		return 1;
	}
	
	if(dp[pos][al][ar][bl][br]!=-1){
		return dp[pos][al][ar][bl][br];
	}
	
	bool least=(l&(1<<pos));
	bool most=(r&(1<<pos));
	
	ll ans=0;
	//choose 0 0
	//x
	//if last_least_unfly -> a>=least else nope
	//if last_most_unfky -> a<=most else nope
	if(check(0,0,al,ar,bl,br,least,most)){
		ans+=dfs(pos-1,((!al)?false:(0==least?true:false)),((!ar)?false:(0==most?true:false)),
					   ((!bl)?false:(0==least?true:false)),((!br)?false:(0==most?true:false))
			);
	}
	if(check(0,1,al,ar,bl,br,least,most)){
		ans+=dfs(pos-1,((!al)?false:(0==least?true:false)),((!ar)?false:(0==most?true:false)),
					   ((!bl)?false:(1==least?true:false)),((!br)?false:(1==most?true:false))
			);
	}
	if(check(1,0,al,ar,bl,br,least,most)){
		ans+=dfs(pos-1,((!al)?false:(1==least?true:false)),((!ar)?false:(1==most?true:false)),
					   ((!bl)?false:(0==least?true:false)),((!br)?false:(0==most?true:false))
			);
	}
//	if(check(1,1,al,ar,bl,br,least,most)){
//		ans+=dfs(pos-1,((!al)?false:(1==least?true:false)),((!ar)?false:(1==most?true:false)),
//					   ((!bl)?false:(1==least?true:false)),((!br)?false:(1==most?true:false))
//			);
//	}
	
	return dp[pos][al][ar][bl][br]=ans;
}

void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>l>>r;
	cout<<dfs(30,1,1,1,1)<<endl;
}
int main(int argc,char* argv[]){
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

