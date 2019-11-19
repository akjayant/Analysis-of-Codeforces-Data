#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
int a[MAX];
bool cmp (int a,int b)
{
	return a>b;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ansa = 0,ansb = 0;
	int mid = (n+1)/2;
	
	for(int i=1;i<=mid;i++)
		ansa += a[i];
		
	for(int i=mid+1;i<=n;i++)
		ansb += a[i];
//	cout<<ansa<<" "<<ansb<<endl;
	cout<<ansa*ansa + ansb*ansb<<endl;  
	return 0;
 } 