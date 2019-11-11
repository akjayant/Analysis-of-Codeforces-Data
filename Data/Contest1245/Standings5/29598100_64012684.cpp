#include<bits/stdc++.h>
using namespace std;


int gcd(int x, int y)
{	
	int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int r, p, s;
        cin >> r >> p >> s;
        string command;
        cin >> command;
        int win = 0;
        string seq(n, ' ');
        int i = 0;
        for(char ch : command)
        {
            if(ch == 'R')
            {
                if(p)
                {
                    p--;
                    win++;
                    seq[i] = 'P';
                }
            }
            else if(ch == 'S')
            {
                if(r)
                {
                    r--;
                    win++;
                    seq[i] = 'R';
                }
            }
            else if(ch == 'P')
            {
                if(s)
                {
                    s--;
                    win++;
                    seq[i] = 'S';
                }
            }
            i++;
        }
        for(i = 0; i < n; i++)
        {
            if(seq[i] == ' ')
            {
                if(p)
                {
                    p--;
                    seq[i] = 'P';        
                }
                else if(s)
                {
                    s--;
                    seq[i] = 'S';
                }
                else if(r)
                {
                    r--;
                    seq[i] = 'R';
                }
            }
        }
        if(win >= ceil(n / 2.0))
        {
            cout << "YES" << endl << seq << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}