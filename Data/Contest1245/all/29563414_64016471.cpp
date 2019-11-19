#include <iostream>
#include <queue>
#include <cstring>
#include <random>

using namespace std;

long long UFDS[2100];
long long sz[2100];
bool power[2100];

long long p(long long n){
	if(n==UFDS[n])
		return n;
	else
		return p(UFDS[n]);
}

bool ss(long long a, long long b){
	return p(a)==p(b);
}

bool hasPower(long long a){
	return power[p(a)];
}

void merge(long long a, long long b){
	if(hasPower(a) || hasPower(b)){
		//result also has power
		if(sz[p(a)] > sz[p(b)]){
			power[p(a)] = true;
			UFDS[p(b)] = p(a);
		} else {
			if(sz[p(a)]==sz[p(b)])
				sz[p(b)]++;
			power[p(b)] = true;
			UFDS[p(a)] = p(b);
		}
	} else {
		if(sz[p(a)]>sz[p(b)]){
			UFDS[p(b)] = p(a);
		} else {
			if(sz[p(a)]==sz[p(b)])
				sz[p(b)]++;
			UFDS[p(a)] = p(b);
		}
		
	}
}

void makePower(long long n){
	power[p(n)] = true;
}

long long x[2100], y[2100];
long long k[2100];
int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	srand(228);
	memset(power, 0, sizeof(power));
	long long N; cin>>N;
	for(long long n=0; n<N; n++){
		UFDS[n] = n;
		sz[n] = 1;
		cin>>x[n]>>y[n];
	}
	// cost, type of action (0=power station, 1=road) one or two numbers showing cities
	priority_queue<pair<long long, pair<long long, pair<long long, long long>>> > q;
	for(long long n=0; n<N; n++){
		long long c;
		cin>>c;
		q.push({-c, {0, {n, n}}});
	}
	for(long long n=0; n<N; n++){
		cin>>k[n];
		for(long long m=0; m<n; m++){
//			cout << k[n] << " " << k[m] << endl;
//			cout << x[n] << " " << x[m] << " " << y[n] << " " << y[m] << endl;
			q.push({-(k[n]+k[m])*(abs(x[n]-x[m]) + abs(y[n]-y[m])), {1, {n, m}}});
		}
	}
	long long totc = 0;
	vector<long long> pows;
	vector<pair<long long, long long>> cit;
	while(!q.empty()){
		long long c = -q.top().first;
		long long t = q.top().second.first;
		long long fr = q.top().second.second.first;
		long long se = q.top().second.second.second;
		q.pop();
	//	cout << c << " " << t <<  " " << fr << " " << se << endl;
		if(t){
			if(ss(fr, se)){
				continue;
			}
			if(hasPower(fr) && hasPower(se))
				continue;
			merge(fr, se);
			cit.push_back({fr, se});
			totc += c;
		} else {
	//		cout << fr << " " << hasPower(fr) << endl;
			if(hasPower(fr)){
				continue;
			} else {
				makePower(fr);
	//			cout << hasPower(fr) << " AA" << endl;
	//			cout << power[0] << endl;
	//			cout << fr << " p" <<  p(fr) << endl;
				totc += c;
				pows.push_back(fr);
			}
		}
	}
	cout << totc << endl;
	cout << pows.size() << endl;
	for(long long n=0; n<pows.size(); n++){
		if(n)
			cout << " ";
		cout << pows[n]+1;
	}
	cout << endl;
	cout << cit.size() << endl;
	for(long long n=0; n<cit.size(); n++)
		cout << cit[n].first+1 << " " << cit[n].second+1 << endl;
	return 0;
}
