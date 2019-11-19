#include <bits/stdc++.h>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

void fillTable(bool *primes, int lastNumber, vector<int> &primesList){
	primesList.clear();
	memset(primes, 1, (lastNumber+1) * sizeof(bool));
	primes[0] = primes[1] = false;
	for (int i = 2; i <= lastNumber; i++){
		if (primes[i]){
			primesList.push_back(i);
			int value = i + i;
			while(value <= lastNumber){
				primes[value] = false;
				value += i;
			}
		}
	}
}

bool primes[2000001];

int main(){
	optimizar_io;
	vector<int> primesList;
	fillTable(primes, 2000000, primesList);
	long long n;
	cin >> n;
	if (n == 1){
		cout << 1 << endl;
	} else {
		bool found = false;
		for (int i = 0; i < primesList.size(); i++){
			if (n % primesList[i] == 0){
				while(n % primesList[i] == 0){
					n /= primesList[i];
				}
				if (n == 1){
					cout << primesList[i] << endl;
					return 0;
				} else {
					cout << 1 << endl;
					return 0;
				}
			}
		}
		cout << n << endl;
	}
	return 0;
}
