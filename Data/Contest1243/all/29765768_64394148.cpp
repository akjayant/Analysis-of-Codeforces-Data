#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	long long n,k,i;
	vector<long long> primes;
	cin>>n;
	k = n;
	for(i=2; i<=1000000; i++){
		if(k % i == 0){
			primes.push_back(i);
			while(k % i == 0){
				k /= i;
			}
		}
	}
	if(k > 1)
	primes.push_back(k);

	if(n == 1)
	cout<<1<<endl;
	else if(primes.size() >= 2)
	cout<<1<<endl;
	else
	cout<<primes[0]<<endl;
}