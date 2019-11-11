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

string s;
int n;
const ll mod=1e9+7;

int dp[100005];
int dfs(int pos){
	if(pos==n){
		return 1;
	}
	
	if(dp[pos]!=-1){
		return dp[pos];
	}
	
	ll ans=0;
	if(pos<n-1 && s[pos]=='u' && s[pos+1]=='u'){
		ans+=dfs(pos+2);
		if(ans>=mod){
			ans-=mod;
		}
	}
	if(pos<n-1 && s[pos]=='n' && s[pos+1]=='n'){
		ans+=dfs(pos+2);
		if(ans>=mod){
			ans-=mod;
		}
	}
	ans+=dfs(pos+1);
	if(ans>=mod){
		ans-=mod;
	}
	
	return dp[pos]=ans;
}

int main(int argc,char* argv[]){
	memset(dp,-1,sizeof(dp));
	
	qi;
	cin>>s;
	
	n=s.size();
	
	for(int i=0;i<n;i++){
		if(s[i]=='m' || s[i]=='w'){
			cout<<0;
			return 0;
		}
	}
	cout<<dfs(0)<<endl;	
	return 0;
}

