#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	long long int N, M; cin >> N >> M; 
	long long int P = 1e9 + 7; 
	long long int pow2[100] = {}; 
	pow2[0] = 2; 
	for(int i = 1; i < 80; i++){
		pow2[i] = pow2[i-1] * pow2[i-1] % P; 
	}
	long long int first = 1; 
	for(int i = 0; i < 50; i++){
		if((M >> i) & 1){
			first *= pow2[i]; 
			first %= P; 
		}
	}
	first += 1e9 + 6; 
	first %= P; 
	long long int pow[100] = {}; 
	pow[0] = first; 
	for(int i = 1; i < 80; i++){
		pow[i] = pow[i-1] * pow[i-1] % P; 
	}
	long long int ans = 1; 
	for(int i = 0; i < 50; i++){
		if((N >> i) & 1){
			ans *= pow[i]; 
			ans %= P; 
		}
	}
	cout << ans << endl; 
}