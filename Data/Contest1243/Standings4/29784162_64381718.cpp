#include <iostream>
#include <string>

using namespace std;

#define ll long long

int main()
{
    ll k, n;
    
    string s, t;
    
    cin >> k;
    
    while(k--)
    {
        cin >> n;
        
        cin >> s >> t;
        
        ll num_of_diff = 0;
        
        ll first_idx = -1;
        ll second_idx = -1;
        
        for (ll i = 0; i < n; ++i)
        {
            if (s[i] != t[i])
            {
                if (num_of_diff == 0)
                {
                    first_idx = i;
                }
                else if (num_of_diff == 1)
                {
                    second_idx = i;
                }
                
                ++num_of_diff;
            }
        }
        
        if (num_of_diff == 0)
        {
            cout << "Yes" << endl;
        }
        else if (num_of_diff == 2)
        {
            if ((s[first_idx] == s[second_idx]) && (t[first_idx] == t[second_idx]))
            {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
