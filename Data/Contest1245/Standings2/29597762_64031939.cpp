#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main(){
	int grid[100];
	double exp[100] = {0};
	double bexp[100] = {0};
	for(int i=0; i<100; i++)
			cin >> grid[i];
	for(int i=10; i<100; i+=20)
		for(int j=0; j<5; j++)
			swap(grid[i+j], grid[i+9-j]);
	for(int i=0; i<100; i+=10)
		for(int j=0; j<10; j++)
			grid[i+j] = grid[i+j] * 10 + (-9 + j*2)*(grid[i+j]%2);
	for(int i=1; i<=6; i++)
		bexp[i] = exp[i] = 6;
	for(int i=7; i<100; i++){
		exp[i] = 1;
		for(int d=1; d<=6; d++)
			exp[i] += bexp[i-d] / 6;
		bexp[i] = min(exp[i], exp[i-grid[i]]);
	}
	/*
	for(int i=0; i<100; i++)
		cout << "(" << i << ", " << grid[i] << ") ";
	cout << endl;
	for(int i=0; i<100; i++)
		cout << "(" << exp[i] << ", " << bexp[i] << ") ";
	cout << endl;
	*/
	cout << setprecision(7) << fixed << bexp[99] << endl;
}

