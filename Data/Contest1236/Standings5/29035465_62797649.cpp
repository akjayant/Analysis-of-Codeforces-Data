#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> group[310];

int main()
{	
	cin>>n;
	int num = n * n;
	while(true)
	{
		for(int g = 1; g <= n; ++g)
		{
			group[g].push_back(num--);
		}
		if(num == 0)
			break;
		for(int g = n; g >= 1; --g)
		{
			group[g].push_back(num--);
		}
		if(num == 0)
			break;
	}
	for(int g = 1; g <= n; ++g)
	{
		for(int lab: group[g])
			cout<<lab<<" ";
		cout<<endl;
	}
	return 0;
}
