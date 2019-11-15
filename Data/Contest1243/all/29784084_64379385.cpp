#include <bits/stdc++.h>
using namespace std;

int q;
int n;
string s, t;
int f1[300], f2[300];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--)
    {
        cin >> n >> s >> t;

        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        int nrPozDif = 0;

        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
            {
                nrPozDif++;
                f1[s[i]]++;
                f2[t[i]]++;
            }

        int cate1 = 0, cate2 = 0;
        for (int i = 'a'; i <= 'z'; i++)
            if (f1[i])
                cate1++;
        for (int i = 'a'; i <= 'z'; i++)
            if (f2[i])
                cate2++;
        
        if (nrPozDif == 2 && cate1 == 1 && cate2 == 1)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    

    return 0;
}