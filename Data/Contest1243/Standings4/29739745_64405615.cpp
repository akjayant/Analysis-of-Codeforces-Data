#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
struct node
{
    int x, y;
}      P[1000];
string s, t;
int main()
{
    ios::sync_with_stdio(0);
    int k, n;
    cin >> k;
    while (k--)
    {
        map<int, int> ma;
        cin >> n >> s >> t;
        for (int i = 0; i < n; i++)
            ma[s[i]]++, ma[t[i]]++;
        bool flag = 0;
        for (char i = 'a'; i <= 'z'; i++)
            if (ma[i] & 1)
                flag = 1;
        if (flag)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            int mid = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != t[i])
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (s[i] == s[j])
                        {
                            P[mid].x = j; P[mid].y = i;
                            swap(s[j], t[i]); mid++;
                            break;
                        }
                        else if (t[i] == t[j])
                        {
                            P[mid].x = i; P[mid].y = j;
                            swap(s[i], t[j]); mid++;
                            break;
                        }
                        else if (s[i] == t[j])
                        {
                            P[mid].x = j; P[mid].y = j;
                            swap(s[j], t[j]); mid++;
                            P[mid].x = j; P[mid].y = i;
                            swap(s[j], t[i]); mid++;
                            break;
                        }
                        else if (t[i] == s[j])
                        {
                            P[mid].x = j; P[mid].y = j;
                            swap(s[j], t[j]); mid++;
                            P[mid].x = i; P[mid].y = j;
                            swap(s[i], t[j]); mid++;
                            break;
                        }
                    }
                }
            }
            cout << mid << endl;
            for (int i = 0; i < mid; i++)
                cout << P[i].x + 1 << " " << P[i].y + 1 << endl;
        }
    }
}
