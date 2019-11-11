#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

int gcd(int a, int b){return b?gcd(b,a%b):a;}

int main()
{
	int t;
	cin >> t;
	for(int loop=0;loop<t;loop++)
	{
		int a,b;
		cin >> a >> b;
		bool flag=false;
		if(gcd(a,b)!=1)flag=true;


		cout << (flag ? "Infinite":"Finite") << endl;
	}

}