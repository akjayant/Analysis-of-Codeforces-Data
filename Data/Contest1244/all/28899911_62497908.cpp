#include<bits/stdc++.h>

/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).
*/
using namespace std;

#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()

const LL MOD = (1e9) + 7 ;
const LD EPS = 0.0000001 ;

LL pows(LL a, LL b)
{
	if (b == 0) return 1LL;
	LL temp = pows(a, b / 2);
	temp = (temp * temp) % MOD;
	if (b % 2) temp = (temp * a) % MOD;
	return temp;
}

const int N = 100000 + 5000;

vector<int> graph[N];

LL cost[N][3];
int n;
int degree[N];
bool flag = false;
vector<int> arr;

void dfs(int node, int pa)
{
	int child = 0;
	for (auto it : graph[node]){
		if (it == pa) continue;
		child++;
		dfs(it, node);
	}
	if (child > 1){
		flag = false;
	}
	arr.PB(node);
}

LL cache[N][3][3];

LL solve(int f, int s)
{
	LL res = cost[arr[0]][f] + cost[arr[1]][s];
	int t;
	if ((f == 0 && s == 1) || (f == 1 && s == 0)) t = 2;
	if ((f == 1 && s == 2) || (f == 2 && s == 1)) t = 0;
	if ((f == 2 && s == 0) || (f == 0 && s == 2)) t = 1;
	for (int i = 2; i < n; i++){
		if ((i % 3) == 0) res += cost[arr[i]][f];
		else if ((i % 3) == 1) res += cost[arr[i]][s];
		else res += cost[arr[i]][t];
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < 3; i++){
    	for (int j = 1; j <= n; j++) cin >> cost[j][i];
    }

	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		graph[a].PB(b);
		graph[b].PB(a);
		degree[a]++;
		degree[b]++;
	}

	for (int i = 1; i <= n; i++){
		if (degree[i] == 1){
			flag = true;
			dfs(i, 0);
			break;
		}
	}

	if (!flag){
		cout << "-1\n";
		return 0;
	}
	
	LL ans = 1e18;
	int l1, l2;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (i == j) continue;
			LL temp = solve(i, j);
			if (temp < ans){
				ans = temp;
				l1 = i;
				l2 = j;
			}
		}
	}

	cout << ans << endl;
	int f = l1;
	int s = l2;
	int t;
	if ((f == 0 && s == 1) || (f == 1 && s == 0)) t = 2;
	if ((f == 1 && s == 2) || (f == 2 && s == 1)) t = 0;
	if ((f == 2 && s == 0) || (f == 0 && s == 2)) t = 1;
	int col[N];
	for (int i = 0; i < n; i++){
		if ((i % 3) == 1) col[arr[i]] = s;
		if ((i % 3) == 0) col[arr[i]] = f;
		if ((i % 3) == 2) col[arr[i]] = t;
	}

	for (int i = 1; i <= n; i++) cout << col[i] + 1 << " ";

	return 0;
}