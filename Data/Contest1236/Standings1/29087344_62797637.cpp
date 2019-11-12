#include <iostream>
#include <cstdio>

using namespace std;

int sol[305][305];

int main() {
	int n;
	cin >>n;
	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<n ; j++) {
			if (i%2)
				sol[n-j-1][i] = i*n+j+1;
			else
				sol[j][i] = i*n+j+1;
		}
	}
	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<n ; j++) {
			cout <<sol[i][j]<<" ";
		}
		cout <<endl;
	}
	return 0;
}