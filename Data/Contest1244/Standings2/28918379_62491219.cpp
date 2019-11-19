#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

long long n, k;

set<long long> keys;
unordered_map<long long, long long> count;
long long tint;

void operation(){
	if(count[*keys.begin()] < count[*(--keys.end())]){
		//increase
		long long c = count[*keys.begin()];
		long long curr = *keys.begin();
		long long next = *(++keys.begin());
		if(c * (next - curr) <= k){
			k -= c * (next - curr);
			count[next] += count[curr];
			count[curr] = 0;
			keys.erase(keys.begin());
			return;
		}
		long long maxp = k / c;
		k = 0;
		keys.erase(keys.begin());
		keys.insert(curr + maxp);
		return;
	}
	else{
		//decrease
		long long c = count[*(--keys.end())];
		long long curr = *(--keys.end());
		long long prev = *(--(--keys.end()));
		if(c * (curr - prev) <= k){
			k -= c * (curr - prev);
			count[prev] += count[curr];
			count[curr] = 0;
			keys.erase(--keys.end());
			return;
		}
		long long maxp = k / c;
		k = 0;
		keys.erase(--keys.end());
		keys.insert(curr - maxp);
		return;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> tint;
		keys.insert(tint);
		count[tint]++;
	}
	while(k && keys.size() > 1) operation();
	cout << *(--keys.end()) - *keys.begin();
}