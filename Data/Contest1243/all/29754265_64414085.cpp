#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


const int n1 = 55;
int arr[n1];
int arr1[n1];

pair<int, int> searchy(int ind, int pval)
{
   for (int i = 0; i < 55; ++i)
   {
       if(arr[i] == pval)
       {
          return pair<int, int>(0, i);
       }
       if(arr1[i] == pval)
       {
        return pair<int, int>(1, i);
       }
   }
}



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

        vector<pair<int, int> > f[26];
        

        for (int i = 0; i < n; ++i)
        {
            f[sa[i] - 'a'].push_back(pair<int, int>(0, i));
            f[sb[i] - 'a'].push_back(pair<int, int>(1, i));
        }

        bool fg = 0;
        for (int i = 0; i < 26; ++i)
        {
            int sz = f[i].size();
            if(sz&1) fg = 1;
        }

        if(fg)
        {
            cout << "No\n";
            continue;
        }


     

        

        int turn = 1;


        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < f[i].size(); j += 2)
             {
                 if(f[i][j].first == 0)
                 {
                     arr[f[i][j].second] = turn;
                 }
                 else
                 {
                    arr1[f[i][j].second] = turn;
                 }

                 if(f[i][j + 1].first == 0)
                 {
                     arr[f[i][j + 1].second] = turn + n;
                 }
                 else
                 {
                    arr1[f[i][j + 1].second] = turn + n;
                 }

                 turn++;
             }

        }



        // for (int i = 0; i < n; ++i)
        // {
        //    cout << arr[i] << " ";
        // }
        // cout << "\n";

        // for (int i = 0; i < n; ++i)
        // {
        //     cout << arr1[i] << " ";
        // }
        // cout << "\n";


        vector<pair<int, int> > ans;

        for (int i = 0; i < n; ++i)
        {
            int pval;

            if(arr1[i] > n) pval = arr1[i] - n;
            else pval = arr1[i] + n;

            pair<int, int> p = searchy(i, pval);

            if(p.first == 1)
            {
                swap(arr[i], arr1[p.second]);
                ans.push_back(pair<int, int>(i, p.second) );
                continue;
            }

            ans.push_back(pair<int, int>(i, i));

            swap(arr[i], arr1[i]);

            if(p.second == i) continue;

            ans.push_back(pair<int, int>(p.second, i));
            swap(arr1[i], arr[p.second]);

        }

        cout << "Yes\n";

        cout << ans.size() << "\n";

        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
        }



        

        
    }
    

    return 0;
}