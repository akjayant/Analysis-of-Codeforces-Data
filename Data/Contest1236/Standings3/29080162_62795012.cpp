#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > v(3001);

int main()
{
    int n;
    cin >> n;
    int q = 1;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(flag == 0)
        {
            int j = 0;
            while(j < n)
            {
                v[j].push_back(q);
                q++;
                j++;
            }
            flag = 1;
        }
        else
        {
            int j = n - 1;
            while(j > -1)
            {
                v[j].push_back(q);
                q++;
                j--;
            }
            flag = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }

}
