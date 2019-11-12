#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int A[100000];
int N,a,b,c,ans;
int main()
{
	cin>>N;
	for(int i=0 ; i<N ; i++){
		cin>>a>>b>>c;
		cout<<(min(c/2,b)+min((b-min(c/2,b))/2, a))*3<<"\n";
	}
}