#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string str;
        cin >> n >> str;
        int maxi = 0;
        for(int i = 0; i < n; ++i)
        {
            if(str[i] == '1')
            {
                if(maxi < i+1)
                    maxi = i+1;
                if(maxi < n-i)
                    maxi = n-i;
            }
        }
        if(maxi == 0)
            cout << n << endl;
        else
            cout << maxi * 2 << endl;
    }
    return 0;
}
