#include <bits/stdc++.h>

using namespace std;

struct pp {
	long long val;
	long long count;
};

int main() {
	cin.tie(0);
	cout.tie(0);
	iostream::sync_with_stdio(0);
	long long n, k;
	cin>>n>>k;
	long long a[100005];
	for (long long i = 1; i <= n; i++)
		cin>>a[i];
	sort(a + 1, a + n + 1);
	vector < pp > d;
	pp ed;
	ed.val = a[1], ed.count = 1;
	d.push_back(ed);
	for (long long i = 2; i <= n; i++) {
		if (a[i] == a[i - 1])
			d[d.size() - 1].count++;
		else {
			ed.val = a[i];
			ed.count = 1;
			d.push_back(ed);
		}
	}
	long long bot = 0, top = d.size() - 1; 
	while (k > 0) {
		if (bot == top) {
			cout<<"0";
			return 0;
		}
		long long first = d[bot].count * (d[bot + 1].val - d[bot].val);
		long long second = d[top].count * (d[top].val - d[top - 1].val);
		if (d[bot].count <= d[top].count) { //move up
			if (first <= k) {
				bot++;
				d[bot].count += d[bot - 1].count;
				k -= first;
				continue;
			}
			long long c = k / d[bot].count;
			cout<<(d[top].val - d[bot].val - c)<<endl;
			return 0;
		} else { //move down
			if (second <= k) {
				top--;
				d[top].count += d[top + 1].count;
				k -= second;
				continue;
			}
			long long c = k / d[top].count;
			cout<<(d[top].val - d[bot].val - c)<<endl;
			return 0;
		}
	}
	cout<<d[top].val-d[bot].val<<endl;
}