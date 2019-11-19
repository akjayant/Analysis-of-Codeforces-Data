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

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		ll o = 0, z = 0;
		fr(i,0,n) {
			int q;
			sf("%d",&q);
			if(q&1)o++;
			else z++;
		}

		int m;
		cin>>m;
		ll o1 = 0, z1 = 0;
		fr(i,0,m) {
			int q;
			sf("%d",&q);
			if(q&1)o1++;
			else z1++;
		}

		cout<<(o*o1)+z*z1<<endl;
	}
}
