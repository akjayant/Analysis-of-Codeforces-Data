#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;

const int maxx = 1e7 + 5;
const double PI = acos(-1.0);
const long long inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n, m, T;
int a[555][555];

int main(){
	int i, j, k, ans;
	while(scanf("%d", &n) == 1){
		k = 1; ans = 0;
		for(i = 1; i <= n; i++){
			if(i & 1){
				for(j = 1; j <= n; j++) a[i][j] = k++;
			}else{
				for(j = n; j >= 1; j--) a[i][j] = k++;
			}
		}
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				if(j != n) printf("%d ", a[j][i]);
				else printf("%d", a[j][i]);
			}
			puts("");
		}
	}
	return 0;
}