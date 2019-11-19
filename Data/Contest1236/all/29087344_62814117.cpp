#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

typedef long long ll;

set<int> r[100005];
set<int> s[100005];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i=0 ; i<k ; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		r[x].insert(y);
		s[y].insert(x);
	}
	int minx = 0;
	int miny = 0;
	int maxx = n+1;
	int maxy = m+1;
	int posx = 1;
	int posy = 1; 
	ll br = 0;
	for (int i=0 ; i<=2*(n+m) ; i++) {
		/*cout <<"i="<<i<<endl;
		cout <<"posx = "<<posx<<endl;
		cout <<"posy = "<<posy<<endl;*/
		ll move = 0;
		if (i%4 == 0) {
			int newy = maxy;
			set <int> :: iterator nxt = r[posx].upper_bound(posy);
			if (nxt!=r[posx].end() and *nxt<newy) newy = *nxt;
			newy--;
			move = newy-posy;
			posy = newy;
			minx = posx;
		}
		if (i%4 == 1) {
			int newx = maxx;
			set <int> :: iterator nxt = s[posy].upper_bound(posx);
			if (nxt!=s[posy].end() and *nxt<newx) newx = *nxt;
			newx--;
			move = newx-posx;
			posx = newx;
			maxy = posy;
		}
		if (i%4 == 2) {
		//	cout <<1<<endl;
			int newy = miny;
			set <int> :: iterator nxt = r[posx].upper_bound(posy);
		//	cout <<2<<endl;
			if (r[posx].size() and nxt!=r[posx].begin()) {
				nxt--;
				newy = max(newy, *nxt);
			}
		//	cout <<3<<endl;
			newy++;
			move = posy-newy;
			posy = newy;
			maxx = posx;
		}
		if (i%4 == 3) {
			int newx = minx;
			set <int> :: iterator nxt = s[posy].upper_bound(posx);
			if (s[posy].size() and nxt!=s[posy].begin()) {
				nxt--;
		//		cout <<"asdfji  "<<*nxt<<endl;
				newx = max(newx, *nxt);
			}
			newx++;
			move = posx-newx;
			posx = newx;
			miny = posy;
		}
		if (move == 0 and i) break;
		br += move;
	//	cout <<"br = "<<br<<endl;
	}
	if (br<(long long)n*m-k-1) printf("No\n");
	else printf("Yes\n");
	return 0;
}