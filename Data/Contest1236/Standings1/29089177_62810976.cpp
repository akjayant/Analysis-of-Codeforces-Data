// IN THE NAME OF ALLAH.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back

const int N = 1000 * 100 + 100;
set<int> row[N], col[N], rrow[N], rcol[N];


bool checkRow(int x1, int y1, int x2, int y2){
	for(int i = x1; i < x2; i++){
		for(int j = y1; j < y2; j++){
			if(row[i].find(j) == row[i].end())
				return false;
			row[i].erase(j);
			col[j].erase(i);
			rrow[i].erase(-j);
			rcol[j].erase(-i);
		}
	}
	return true;
}


bool checkCol(int x1, int y1, int x2, int y2){
	//cout << "Mashti";
	for(int j = y1; j < y2; j++){
		for(int i = x1; i < x2; i++){
			//cout << i << ' ' << j << "check\n";
			if(col[j].find(i) == col[j].end())
				return false;
			row[i].erase(j);
			col[j].erase(i);
			rrow[i].erase(-j);
			rcol[j].erase(-i);
		}
	}
	return true;
}



int32_t main(){
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		x--;y--;
		row[x].insert(y);
		col[y].insert(x);
		rrow[x].insert(-y);
		rcol[y].insert(-x);
	}
	int up = 0,
		down = n,
		right = m,
		left = 0;
	while(true){
		if(row[up].size() != 0){
			int t = *(row[up].begin());
			if(checkCol(up, *(row[up].begin()), down, right) == false){
				cout << "No\n";
				return 0;
			}
			right = t;
			if(left >= right)
				break;
		}
		up++;
		if(up >= down)
			break;
		if(col[right - 1].size() != 0){
			int t = *(col[right - 1].begin());
			if(checkRow(*(col[right - 1].begin()), left, down, right) == false){
				cout << "No\n";
				return 0;
			}
			down = t;
			if(up >= down)
				break;
		}
		//cout << 1 << endl;
		right--;
		if(right <= left)
			break;
		if(rrow[down - 1].size() != 0){
			int t = -(*(rrow[down - 1].begin()));
			//cout << "OMadim to\n";
			//cout << up << ' '  << right << ' '  << left << ' ' << down << '\n';
			if(checkCol(up, left, down, t + 1) == false){
				cout << "No\n";
				return 0;
			}
			left = t + 1;
			if(left >= right)
				break;
		}
		down--;
		if(up >= down)
			break;
		//cout << 2 << endl;
		if(rcol[left].size() != 0){
			int t = -(*(rcol[left].begin()));
			if(checkRow(up, left, t + 1, right) == false){
				cout << "No\n";
				return 0;
			}
			up = t + 1;
			if(up >= down)
				break;
		}
		left++;
		if(left >= right)
			break;
		//cout << up << ' '  << right << ' '  << left << ' ' << down << '\n';
	}	
	cout << "Yes\n";
	return 0;
}