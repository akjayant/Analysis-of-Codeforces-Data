#include<iostream>
#include<algorithm>
#include<memory.h>
#include<unordered_map>
#include<queue>
#include<ctime>
#define int long long
using namespace std;

int akari[100010];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,i,a,b;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>akari[i];
	}
	
	sort(akari,akari+n);
	a=b=0;
	for(i=0;i<n;i++)
	{
		if(i<n/2)
			a+=akari[i];
		else
			b+=akari[i];
	}
	cout<<a*a+b*b<<'\n';
	
	return 0;
}
