#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#define MOD 1000000007
using namespace std;


int Pow(int a, int r){
	if (r == 0) return 1;
	int a2 = Pow(a, r / 2);
	int a3 = (long long) (a2) * a2 % MOD;
	int a4 = (long long) (a3) * a % MOD;
	if (r % 2 == 0) return a3;
	else return a4;
}
int main(){
	int n, m;
	cin >> n >> m;
	cout << Pow((Pow(2, m) + MOD - 1) % MOD, n) << endl; 
	return 0;
}