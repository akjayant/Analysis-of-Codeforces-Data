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

int n,a[4];
string s;
int ch[1005];
int main(int argc,char* argv[]){
	int t;
	cin>>t;
	ch['R']=0;
	ch['P']=1;
	ch['S']=2;
	
	while(t--){
		cin>>n;
		cin>>a[0]>>a[1]>>a[2];
		cin>>s;
		string ans;
		for(int i=0;i<s.size();i++){
			ans+='?';
		}
		
		int win=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='R'){
				if(a[1]){
					a[1]--;
					ans[i]='P';
					win++;
				}
			}
			if(s[i]=='P'){
				if(a[2]){
					a[2]--;
					ans[i]='S';
					win++;
				}
			}
			if(s[i]=='S'){
				if(a[0]){
					a[0]--;
					ans[i]='R';
					win++;
				}
			}
		}
		
		
		for(int i=0;i<s.size();i++){
			if(ans[i]=='?'){
				if(a[0]){
					a[0]--;
					ans[i]='R';
				}else if(a[1]){
					a[1]--;
					ans[i]='P';
				}else if(a[2]){
					a[2]--;
					ans[i]='S';
				}
			}
		}
		
		if(win>=(n+1)/2){
			cout<<"YES"<<endl<<ans<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

