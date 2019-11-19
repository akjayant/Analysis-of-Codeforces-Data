#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;

int a[MAX],b[MAX];

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x;
		long long  aji = 0, aou = 0, bji = 0, bou = 0;
		for(int i=0;i<x;i++){
			cin>>a[i];
			if(abs(a[i])%2==0) aou++;
			else aji++;
		}
			
		cin>>y;
		for(int i=0;i<y;i++){
			cin>>b[i];
			if(abs(b[i])%2 == 0) bou++;
			else bji++;
		}
		
		cout<<aji*bji + aou*bou<<endl;
	}
	return 0;
 } 