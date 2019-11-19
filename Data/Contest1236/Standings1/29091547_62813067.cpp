#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int L = 1e5+10;
vector<int> onRow[L];
vector<int> onCol[L];

int primeiroMenor(vector<int> &v, int x){
	int l = 0, m, r = v.size()-1;
	while(l<=r){
		m = (l+r)>>1;
		if(v[m] < x) l = m+1;
		else r = m-1;
	}
	return v[r];
}

int primeiroMaior(vector<int> &v, int x){
	int l = 0, m, r = v.size()-1;
	while(l<=r){
		m = (l+r)>>1;
		if(v[m] <= x) l = m+1;
		else r = m-1;
	}
	return v[l];
}

int cnt = 0;
ll sz;

int imaj, imen=0, jmaj, jmen=0;
void explore(int i = 1, int j = 1, int dir = 1, bool ini = 1){

	//if(++cnt==11) return;
	//cout << i << ' ' << j << " : " << dir << " faltam " << sz << '\n';
	//cout << "linha " << imen << " - " << imaj << "   col " << jmen << " - " << jmaj << "\n";

	if(dir == 1){
		int stopj = primeiroMaior(onRow[i], j);
		stopj = min(stopj, jmaj);
		jmaj = stopj;
		stopj--;
		imen = i;
		int dist = stopj-j;
		if(dist <= 0){
			if(ini) explore(i, j, 2, 0);
			else return;
		}
		else{
			sz -= dist;
			explore(i, stopj, 2, 0);
		}
	}
	else if(dir == 2){
		int stopi = primeiroMaior(onCol[j], i);
		stopi = min(stopi, imaj);
		imaj = stopi;
		stopi--;
		jmaj = j;
		int dist = stopi-i;
		if(dist <= 0) return;
		else{
			sz -= dist;
			explore(stopi, j, 3, 0);
		}
	}
	else if(dir == 3){
		int stopj = primeiroMenor(onRow[i], j);
		stopj = max(stopj, jmen);
		jmen = stopj;
		stopj++;
		imaj = i;
		int dist = j-stopj;
		if(dist <= 0) return;
		else{
			sz -= dist;
			explore(i, stopj, 4, 0);
		}
	}
	else{
		int stopi = primeiroMenor(onCol[j], i);
		stopi = max(stopi, imen);
		imen = stopi;
		stopi++;
		jmen = j;
		int dist = i-stopi;
		if(dist <= 0) return;
		else{
			sz -= dist;
			explore(stopi, j, 1, 0);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int qt;
	cin >> imaj >> jmaj >> qt;
	sz = imaj;
	sz *= jmaj;
	sz -= (qt+1);
	imaj++;
	jmaj++;

	for(int i=0, x, y; i<qt; i++){
		cin >> x >> y;
		onRow[x].push_back(y);
		onCol[y].push_back(x);
	}

	for(int i=0; i<L; i++){
		onRow[i].push_back(0);
		onRow[i].push_back(L);
		onCol[i].push_back(0);
		onCol[i].push_back(L);
		sort(onRow[i].begin(), onRow[i].end());
		sort(onCol[i].begin(), onCol[i].end());
	}

	explore();

	if(sz == 0) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}