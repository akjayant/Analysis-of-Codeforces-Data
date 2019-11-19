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

ll sqr(ll a, ll b) {
	return a*a+b*b;
}

int main(){
	int n;
	cin>>n;
	ll tot = 0;
	fr(i,0,n) {
		sf("%d",&a[i]);
		tot += a[i];
	}
	sort(a,a+n);
	ll ans = tot;
	ll sum = 0;
	fr(i,0,n/2) {
		sum += a[i];
	}
	cout<<sqr(sum,tot-sum)<<endl;
}

