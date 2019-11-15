
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack> 
#include <map>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;



int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int main() {
    //ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a>>b;
		int g = gcd(a, b);
		if(g==1)
			cout<<"Finite\n";
		else
			cout<<"Infinite\n";

	}

	return 0;
}

