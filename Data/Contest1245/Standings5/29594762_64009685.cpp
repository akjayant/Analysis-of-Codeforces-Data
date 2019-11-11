#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>
#include<map>

using namespace std;

//map<char,int>('r':0,'c':1,'p':2);

int main()
{
	int t;
	cin >> t;
	for(int loop=0;loop<t;loop++)
	{
		int n,a,b,c;
		cin >> n >> a >> b >> c;
		string s;
		cin >> s;

		int aa,bb,cc;
		aa=a;
		bb=b;
		cc=c;
		int cnt=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='R' and b>0)
			{
				b--;
				cnt++;
			}
			else if(s[i]=='S' and a>0)
			{
				a--;
				cnt++;
			}
			else if(s[i]=='P' and c>0)
			{
				c--;
				cnt++;
			}
		}
		if(cnt*2>=n)
		{
			cout << "YES" << endl;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='R' and bb>0)
				{
					bb--;
					cout << 'P';
				}
				else if(s[i]=='S' and aa>0)
				{
					aa--;
					cout << 'R';
				}
				else if(s[i]=='P' and cc>0)
				{
					cc--;
					cout << 'S';
				}
				else
				{
					if(a>0)
					{
						cout << 'R';
						a--;
					}
					else if(b>0)
					{
						cout << 'P';
						b--;
					}
					else if(c>0)
					{
						cout << 'S';
						c--;
					}
				}
			}
			cout << endl;
		}
		else
			cout << "NO" << endl;

	}

}