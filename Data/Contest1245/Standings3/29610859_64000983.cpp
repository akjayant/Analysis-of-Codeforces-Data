#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;
#define fio ios::sync_with_stdio(fasle); cin.tie(NULL);

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INT_INF = 1e9;
const ll LL_INF = 1e18;
const int MAXN = 500010;

typedef struct GE{
	int to;
	ll w;
}GE;

int n, m;
char o[MAXN];

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		int r, p, s;
		scanf("%d %d %d", &r, &p, &s);
		scanf("%s", o);
		int ol = strlen(o);
		int rcnt=0, pcnt=0, scnt=0;
		for(int i=0;i<ol;i++){
			if(o[i]=='R') rcnt++;
			else if(o[i]=='P') pcnt++;
			else scnt++;
		}

		int ans = min(rcnt, p)+min(pcnt, s)+min(scnt, r);
		if(ans>=(n+1)/2) {
			puts("YES");

			int rrem = min(rcnt, p);
			int prem = min(pcnt, s);
			int srem = min(scnt, r);
			p -= rcnt;
			s-=pcnt;
			r-=scnt;
			for(int i=0;i<ol;i++){
				if(o[i]=='R' && rrem>0) {
					printf("P");
					rrem--;
				}
				else if(o[i]=='P' && prem>0) {
					printf("S");
					prem--;
				}
				else if(o[i]=='S' && srem>0) {
					printf("R");
					srem--;
				}
				else {
					if(p>0) {
						p--; 
						printf("P");
					}
					else if(s>0) {
						s--;
						printf("S");
					}
					else {
						r--;
						printf("R");
					}
				}
			}
			puts("");
		}
		else{
			puts("NO");
		}
	}
	

	
	return 0;
}