#include <iostream>
#include <vector>
using namespace std;

int n;

long long c1[100005];
long long c2[100005];
long long c3[100005];

vector<int> graph[100005];

int tint1, tint2;

int dpStart = -1;
int dpEnd = -1;

long long best = ((long long)1 << 50);
int bestPainting[100005];
int tPainting[100005];

long long cost(int v, int c){
	if(c == 0) return c1[v];
	if(c == 1) return c2[v];
	else return c3[v];
}

int nextV(int v, int prev){
	if(graph[v][0] == prev) return graph[v][1];
	else return graph[v][0];	
}

void getCost(int color1, int color2, int color3){
	long long totalCost = 0;
	totalCost += cost(dpStart, color1);
	tPainting[dpStart] = color1;
	int prev = dpStart;
	int curr = graph[dpStart][0];
	int nw = 1;
	for(;;){
		switch(nw % 3){
			case 0:
				totalCost += cost(curr, color1);
				tPainting[curr] = color1;
				break;
			case 1:
				totalCost += cost(curr, color2);
				tPainting[curr] = color2;
				break;
			case 2:
				totalCost += cost(curr, color3);
				tPainting[curr] = color3;
				break;
		}
		if(curr == dpEnd) break;
		nw++;
		int currCopy = curr;
		curr = nextV(curr, prev);
		prev = currCopy;
	}
	if(totalCost < best){
		best = totalCost;
		for(int i = 0; i < n; i++) bestPainting[i] = tPainting[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> c1[i];
	for(int i = 0; i < n; i++) cin >> c2[i];
	for(int i = 0; i < n; i++) cin >> c3[i];
	for(int i = 0; i < n - 1; i++){
		cin >> tint1 >> tint2;
		tint1--;
		tint2--;
		graph[tint1].push_back(tint2);
		graph[tint2].push_back(tint1);
	}
	for(int i = 0; i < n; i++) if(graph[i].size() > 2){
		cout << -1;
		return 0;
	}
	for(int i = 0; i < n; i++) if(graph[i].size() == 1){
		if(dpStart == -1){
			dpStart = i;
			continue;
		}
		dpEnd = i;
	}

	for(int color1 = 0; color1 < 3; color1++) for(int color2 = 0; color2 < 3; color2++) for(int color3 = 0; color3 < 3; color3++)
		if(color1 != color2 && color2 != color3 && color1 != color3) getCost(color1, color2, color3);
	cout << best << "\n";
	for(int i = 0; i < n; i++) cout << bestPainting[i] + 1 << ' ';
}