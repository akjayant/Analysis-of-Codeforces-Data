#include <string.h>
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stdlib.h>    
#include <time.h> 
#include <stack>
#include <queue>
#include <set>
 
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
 
#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define frr(i,a,b) for(int i = a; i > b; --i)
#define pb push_back
#define sf scanf
 
#define pf printf
#define mp make_pair
 
using namespace std;
const int N = 410000;
const int mod = 1000000007;

int a[1000000];

int n;
int l_sum[N],r_sum[N],l_min[N],r_min[N];
int v[N];
string s;

int check() {
	for(int i = 0; i < n; ++i) {
		v[i] = 0;
	}
	//set<int> ans;
//	cout<<s<<endl;
	int t = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i]=='(') t++;
		else t--;
		l_sum[i] = t;
		if(i==0) {
			l_min[i]=l_sum[i];
		}
		else {
			l_min[i] = min(l_min[i-1],l_sum[i]);
		}
	}

	for(int i = 0; i < n; ++i) {
		if(i==0) {
			r_sum[i] = l_sum[n-1];
		}
		else {
			r_sum[i] = l_sum[n-1]-l_sum[i-1];
		}
	}
	if(l_sum[n-1]!=0) {
		return 0;
	}

	for(int i = 0; i < n; ++i) {
		if(i==0) {
			r_min[i] = l_min[n-1];
		}
		else {
			r_min[i] = l_min[n-1] - l_sum[i-1];
		}
	}

	for(int i = 0; i+1 < n; ++i) {
		int t1 = l_min[i];
		int t2 = r_min[i+1];
		if(t1>=0&&t2>=0){
			//printf("v i = %d l = %d r = %d\n",i, l_min[i],r_min[i+1]);
			//ans.insert(i);
			v[i] = 1;
		}
	}

	for(int i = 0; i+1 < n; ++i) {
		int t1 = r_min[i+1];
		int t2 = l_min[i] + r_sum[i+1];
		if(t1>=0&&t2>=0) {
		//	printf("i = %d t1 = %d t2 = %d\n",i,t1,t2);
		//	printf("l min = %d r sum = %d\n",l_min[i],r_sum[i+1]);
			//ans.insert(i);
			v[i] = 1;
		}
	}
	if(l_min[n-1]==0) {
		v[n-1]=1;
		//ans.insert(n);
	}
	int ans = 0;
	fr(i,0,n) if(v[i])++ans;
	return ans;
}

int main(){
	cin>>n;
	cin>>s;
	ll ans = -1;
	pair<int,int> ft;
	for(int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j) {
			swap(s[i],s[j]);
			//printf("i = %d j = %d\n",i,j);
			int ret = check();
			//printf("ret = %d\n",ret);
			if(ret > ans){
				ans = ret;
				ft = mp(i,j);
			}
			swap(s[i],s[j]);
		}
	}
	cout<<ans<<endl;
	printf("%d %d\n",ft.first+1,ft.second+1);
}

