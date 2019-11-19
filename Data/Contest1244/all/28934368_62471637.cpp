#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vl vector<ll>


using namespace std;

int main() 
{
    int a;
    vl ans;
    cin >> a;
    for(int i = 0;i < a;i++)
    {
        int t;
        cin >> t;
        int min = -1, max = 0;
        for(int j = 0;j < t;j++)
        {
            char c;
            cin >> c;
            if(c == '1')
            {
                max = j;
                if(min == -1)
                    min = j;
            }
        }
        
        if(min == -1)
        {
            ans.push_back(t);
            continue;
        }
        
        int res = max + 1 > t - min ? max + 1 : t - min;
        ans.push_back(res * 2);
    }
    
    for(int i = 0;i < ans.size();i++)
        cout << ans[i] << endl;
}