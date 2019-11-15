
// Created by RUPESH
// From https://blog.codingblocks.com/2019/setting-up-a-c-competitive-programming-environment

#include <bits/stdc++.h>


using namespace std;
using ll = long long;

int mgcd(int a , int b){
	if(b == 0) return a;
	return mgcd(b,a%b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int g = mgcd(a,b);
		if (g != 1)
		{
			cout << "Infinite" << endl;
		}
		else{
			cout << "Finite" << endl;
		}
	}
	return 0;
}