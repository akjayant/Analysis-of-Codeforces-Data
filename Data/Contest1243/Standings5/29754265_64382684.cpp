#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string sa, sb;
        cin >> sa >> sb;
        int cnt = 0;

        int ptr1 = -1, ptr2 = -1;

        for (int i = 0; i < n; ++i)
        {
            if(sa[i] != sb[i])
            {
                cnt++;
                if(ptr1 == -1) ptr1 = i;
                else ptr2 = i;
            }
        }

        if(cnt == 1 || cnt > 2)
        {
            cout << "No\n";
            continue;
        }

        if(sa[ptr1] == sa[ptr2] && sb[ptr1] == sb[ptr2])
        {
            cout << "Yes\n";
            continue;
        }

        cout << "No\n";


    }


    return 0;
}