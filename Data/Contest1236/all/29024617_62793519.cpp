#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <array>
#include <set>
#include <bitset>

using namespace std;

vector < int > prvi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int br;
	br=0;
	for(int i=0; i<n; i++){
		prvi.push_back(br);
		if(!(i%2)){
			br+=n*2-1;
		}
		else{
			br++;
		}
		cout << prvi[i]+1 << " ";
	}
	cout << '\n';
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n; j++){
			if(!(j%2)){
				prvi[j]++;
			}
			else{
				prvi[j]--;
			}
			cout << prvi[j]+1 << " ";
		}
		cout << '\n';
	}
	return 0;
}