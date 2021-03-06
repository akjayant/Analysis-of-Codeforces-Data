#include <bits/stdc++.h>
#define VI vector<int>
#define pb push_back
#define LL long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, k;
const int N = 1e5+10;
set<int> R[N], C[N];
int movx[] = {0,1,0,-1};
int movy[] = {1,0,-1,0};
int main(){
	scanf("%d %d %d", &n, &m, &k);
	LL tot = n*1LL*m - k;
	for(int i = 0; i < k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		R[x].insert(y);
		C[y].insert(x);
	}
	int r = 1, c = 1;
	int dir = 0;
	bool change = false;
	int mincol = 0, maxcol = m+1, minrow = 1, maxrow = n+1;
	LL vis = 1LL;
	while(true){
		set<int>::iterator it;
		int pr = r, pc = c;
		if(dir == 0){
			it = R[r].lower_bound(c);
			if(it == R[r].end()) c = m;
			else c = *it - 1;
			c = min(c, maxcol-1);
			maxcol = c;
			vis += llabs(c-pc);
		}else if(dir == 1){
			it = C[c].lower_bound(r);
			if(it == C[c].end()) r = n;
			else r = *it - 1;
			r = min(r, maxrow-1);
			maxrow = r;
			vis += llabs(r-pr);
		}else if(dir == 2){
			it = R[r].lower_bound(c);
			if(it == R[r].begin()) c = 1;
			else c = *(--it) + 1;
			c = max(c, mincol+1);
			mincol = c;
			vis += llabs(c-pc);
		}else{
			it = C[c].lower_bound(r);
			if(it == C[c].begin()) r = 1;
			else r = *(--it) + 1;
			r = max(r, minrow+1);
			minrow = r;
			vis += llabs(r-pr);
		}
		if(pr == r && pc == c){
			if(change) break;
		}
		change = true;
		dir = (dir + 1)%4;
	}
	printf("%s\n", vis == tot ? "Yes":"No");
	return 0;
}