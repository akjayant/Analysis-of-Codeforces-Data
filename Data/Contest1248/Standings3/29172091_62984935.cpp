#include <bits/stdc++.h>

	using namespace std;

#define ll long long
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n; i>=0; i--)
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define st first
#define nd second
#define vi vector<int>
#define vii vector< vi >
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define endl "\n"

ll N;
ll A[100200];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	REP(i, N){
		cin >> A[i];
	}

	sort(A, A+N);
	ll sumL = 0;
	ll sumR = 0;

	REP(i, N/2)
		sumL += A[i];

	REP(i, N/2)
		sumR += A[N-i-1];

	if(N%2 == 0){
		cout << sumR*sumR + sumL*sumL << "\n";
		return 0;
	}

	cout << max((sumR+A[N/2])*(sumR+A[N/2])+sumL*sumL, (sumL+A[N/2])*(sumL+A[N/2])+sumR*sumR) << "\n";

	return 0;
}