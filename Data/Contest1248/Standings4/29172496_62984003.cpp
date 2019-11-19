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

int n;
vector<int> vec;
priority_queue<int> maxpq;
priority_queue<int,vector<int>,greater<int>> minpq;

int main(int argc, char** argv) {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	
	for(int i = 0;i<n;i++)
	{
		int num;
		cin>>num;
		
		maxpq.push(num);
		minpq.push(num);
	}
	
	ll ver = 0; ll hor = 0;
	
	for(int i = 0;i<n;i++)	
	{
		if(i % 2 == 0)
		{
			ver += maxpq.top();
			maxpq.pop();
		}
		else
		{
			hor += minpq.top();
			minpq.pop();
		}
	}
	
	cout<<ver*ver + hor*hor;
	
	

	return 0;
}