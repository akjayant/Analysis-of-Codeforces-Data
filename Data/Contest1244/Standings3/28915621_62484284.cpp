#include <bits/stdc++.h>

using namespace std;

vector < long long > with[100005];

long long color[100005];

long long res[6];

int main() {
	cin.tie(0);
	cout.tie(0);
	iostream::sync_with_stdio(0);
	long long n;
	long long c[4][100005];
	cin>>n;
	for (long long i = 1; i <= 3; i++)
	for (long long j = 1; j <= n; j++)
		cin>>c[i][j];
	for (long long i = 1; i <= n; i++)
		with[i].push_back(0);
	for (long long i = 1; i < n; i++) {
		long long l, r;
		cin>>l>>r;
		with[l][0]++;
		with[l].push_back(r);
		with[r][0]++;
		with[r].push_back(l);
	}
	/*for (long long i = 1; i <= n; i++) {
		cout<<i<<": ";
		for (long long j = 1; j <= with[i][0]; j++)
			cout<<with[i][j]<<" ";
		cout<<endl;
	}*/
	for (long long i = 1; i <= n; i++)
		if (with[i][0] >= 3) {
			cout<<"-1"<<endl;
			return 0;
		}
	int o = 1;
	while (with[o][0] > 1)
		o++;
	color[o] = 1;
	vector < long long > que;
	que.push_back(o);
	long long head = 0, tail = 0;
	while (head <= tail) {
		for (long long i = 1; i <= with[que[head]][0]; i++) {
			if (color[with[que[head]][i]]) continue;
			color[with[que[head]][i]] = (color[que[head]] == 3) ? 1 : (color[que[head]] + 1);
			que.push_back(with[que[head]][i]);
			tail++;
		}
		head++;
	}
	/*for (long long i = 1; i <= n; i++)
		cout<<color[i]<<" ";
	cout<<endl;*/
	long long best[4];
	long long res;
	long long curr;
	//1 2 3
	res = 0;
	for (long long i = 1; i <= n; i++) {
		res += c[color[i]][i];
	}
	if (res <= res) {
		best[1] = 1;
		best[2] = 2;
		best[3] = 3;
		res = res;
	}
	//1 3 2
	curr = 0;
	for (long long i = 1; i <= n; i++) {
		if (color[i] == 1)
			curr += c[1][i];
		else if (color[i] == 2)
			curr += c[3][i];
		else curr += c[2][i];
	}
	if (curr < res) {
		best[1] = 1;
		best[2] = 3;
		best[3] = 2;
		res = curr;
	}
	//2 1 3
	curr = 0;
	for (long long i = 1; i <= n; i++) {
		if (color[i] == 1)
			curr += c[2][i];
		else if (color[i] == 2)
			curr += c[1][i];
		else curr += c[3][i];
	}
	if (curr < res) {
		best[1] = 2;
		best[2] = 1;
		best[3] = 3;
		res = curr;
	}
	//2 3 1
	curr = 0;
	for (long long i = 1; i <= n; i++) {
		if (color[i] == 1)
			curr += c[2][i];
		else if (color[i] == 2)
			curr += c[3][i];
		else curr += c[1][i];
	}
	if (curr < res) {
		best[1] = 2;
		best[2] = 3;
		best[3] = 1;
		res = curr;
	}
	//3 1 2
	curr = 0;
	for (long long i = 1; i <= n; i++) {
		if (color[i] == 1)
			curr += c[3][i];
		else if (color[i] == 2)
			curr += c[1][i];
		else curr += c[2][i];
	}
	if (curr < res) {
		best[1] = 3;
		best[2] = 1;
		best[3] = 2;
		res = curr;
	}
	//3 2 1
	curr = 0;
	for (long long i = 1; i <= n; i++) {
		if (color[i] == 1)
			curr += c[3][i];
		else if (color[i] == 2)
			curr += c[2][i];
		else curr += c[1][i];
	}
	if (curr < res) {
		best[1] = 3;
		best[2] = 2;
		best[3] = 1;
		res = curr;
	}
	cout<<res<<endl;
	for (long long i = 1; i <= n; i++)
		cout<<best[color[i]]<<" ";
}