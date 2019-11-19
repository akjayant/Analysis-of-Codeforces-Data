#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <stack>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;



int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,m;
		cin>>n;
		
		int lodd = 0,leven = 0;
		
		for(int i = 0;i<n;i++)
		{
			int num;
			cin>>num;
			
			if(num % 2 == 0) leven++;
			else lodd++;
		}
		
		cin>>m;
		
		int rodd = 0; int reven = 0;
		for(int i = 0;i<m;i++)
		{
			int num;
			cin>>num;
			
			if(num % 2 == 0) reven++;
			else rodd++;
		}
		
		cout<<1LL *leven * reven + 1LL * lodd * rodd<<"\n";
	}
	return 0;
}