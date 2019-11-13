#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

int chk[20004], ts = 1, A, B;

int main()
{
	int tc; for(scanf("%d", &tc); tc--; ts++){
		scanf("%d %d", &A, &B);
		queue<int> q; 
		q.push(0); chk[0] = ts;
		if(A > B) swap(A, B);
		while(!q.empty()){
			int x = q.front(); q.pop();
			int nxt[] = {x - A, x - B, x + A, x + B};
			for(int i = 0; i < 4; i++){
				if(nxt[i] < 0 || nxt[i] > 2 * B) continue;
				if(chk[nxt[i]] != ts){
					q.push(nxt[i]);
					chk[nxt[i]] = ts;
				}
			}	
		}

		bool ans = true;
		for(int i = 0; i <= A; i++)
			if(chk[i] != ts){
				ans = false; break;
			}
		printf("%s\n", ans ? "Finite" : "Infinite");
	}
	return 0;
}