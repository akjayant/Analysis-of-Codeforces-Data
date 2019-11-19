#include <bits/stdc++.h>

using namespace std;

int n,k;
string s;
string t;
int col[200001];
bool sc = true;
vector<int> pos;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	cin >> s;
	for (int i=0;i<n;i++)
		if (s[i] == s[((i-1)+n)%n])
		{
			if (s[i] == 'B')
				col[i] = col[((i-1)+n)%n] = 1;
			else
				col[i] = col[((i-1)+n)%n] = 2;		
			sc = false;
		}
	if (sc)
	{
		if (k%2 == 1)
		{
			for (int i=0;i<n;i++)
			{
				if (s[i] == 'B')
					cout << 'W';
				else
					cout << 'B';	
			}
		}
		else
			cout << s;
		return 0;
	}
	t = s;	
	for (int i=0;i<n;i++)
	{
		if (col[i])
			t[i] = s[i];
		if (col[i] && !col[(i+1)%n]) // check the middle BB..WW, .WW  BB. 
		{
			pos.clear();
			for (int j=(i+1)%n;;j=(j+1)%n)
			{
				if (col[j])
					break;
				pos.push_back(j);
			}
			if (pos.size() % 2 == 1) // same color : WW...WW
			{
				int cnt = 0;
				for (int j=0;j<(int)pos.size()/2 + 1;j++)
				{
					cnt++;
					if (cnt > k)
					{
						for (int x=j;x<(int)pos.size()/2+1;x++)
						{
							if (k%2 == 1)
							{
								if (t[pos[x]] == 'W')
									t[pos[x]] = 'B';
								else
									t[pos[x]] = 'W';	
							}
						}
						break;
					}	
					if (s[i] == 'W') t[pos[j]] = 'W';
					else t[pos[j]] = 'B';							
				} 
				cnt = 0;
				for (int j=pos.size()-1;j>(int)pos.size()/2;j--)
				{
					cnt++;
					if (cnt > k)
					{
						for (int x=j;x>(int)pos.size()/2;x--)
						{
							if (k%2 == 1)
							{
								if (t[pos[x]] == 'W')
									t[pos[x]] = 'B';
								else
									t[pos[x]] = 'W';	
							}
						}
						break;
					}	
					if (s[i] == 'W') t[pos[j]] = 'W';
					else t[pos[j]] = 'B';
				}
			}
			else // dif color : WW..BB
			{
				int cnt = 0;
				for (int j=0;j<(int)pos.size()/2;j++)
				{
					cnt++;
					if (cnt > k)
					{
						for (int x=j;x<(int)pos.size()/2;x++)
						{
							if (k%2 == 1)
							{
								if (t[pos[x]] == 'W')
									t[pos[x]] = 'B';
								else
									t[pos[x]] = 'W';	
							}
						}
						break;					
					}	
					if (s[i] == 'W') t[pos[j]] = 'W';
					else t[pos[j]] = 'B';
				}
				cnt = 0;
				for (int j=pos.size()-1;j>=(int)pos.size()/2;j--)
				{
					cnt++;
					if (cnt > k)
					{
						for (int x=j;x>=(int)pos.size()/2;x--)
						{
							if (k%2 == 1)
							{
								if (t[pos[x]] == 'W')
									t[pos[x]] = 'B';
								else
									t[pos[x]] = 'W';	
							}
						}
						break;
					}	
					if (s[(pos[pos.size()-1]+1)%n] == 'W') t[pos[j]] = 'W';
					else t[pos[j]] = 'B';
				} 
			}
		}
	}
	cout << t;
}