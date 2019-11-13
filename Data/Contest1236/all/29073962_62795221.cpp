#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#define PII pair<int,int>
#define VI vector<int>
#define VII vector<PII>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define _for0(i, _, n) for(int i=_;i<n;++i)
#define _for1(i, _, n) for(int i=_;i<=n;++i)
#define for0(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define rfor0(i, n) for(int i=n-1;i>=0;i--)
#define rfor1(i, n) for(int i=n;i>=1;i--)
#define all(it, obj) for(auto it=(obj).begin();it!=(obj).end();++it)
#define all_(_, it, obj) for(auto it=_;it!=(obj).end();++it)
#define rall(it, obj) for(auto it=(obj).rbegin();it!=(obj).rend();++it)
#define rall_(_, it, obj) for(auto it=_;it!=(obj).rend();++it)
using namespace std;
typedef long long LL;
#define N 100005
int n; 
vector<int> vec[305];

int main ()
{
	scanf("%d",&n);
	int now = n*n;
	int add = 1;
	int at = 0;
	while ( now > 0 ) {
		if ( add ) {
			vec[at].PB(now);
			if ( at == n-1 ) {
				add = 0;
			} else {
				at++;
			}
		} else {
			vec[at].PB(now);
			if ( at == 0 ) {
				add = 1;
			} else {
				at--;
			}
		}
		now--;
	}
	
	for0(i, n) {
		for0(j, n) {
			printf("%d%c", vec[i][j], j==n-1?'\n':' ');
		}
	}
	return (0);
}

