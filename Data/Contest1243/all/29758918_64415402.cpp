#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int a[2*n+1][2];
        int i,j;
        char temp;
        int k=0;
        int flag=0;
        for(i=0;i<n;i++)
        {
            flag=0;
            if(s[i]==t[i])
                continue;
            for(j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    a[k][0] = j;
                    a[k][1] = i;
                    k++;
                    temp = s[j];
                    s[j] = t[i];
                    t[i] = temp;
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                for(j=i+1;j<n;j++)
                {
                    if(t[j]==s[i])
                    {
                        a[k][0] = j;
                        a[k][1] = j;
                        k++;
                        temp = s[j];
                        s[j] = t[j];
                        t[j] = temp;
                        a[k][0] = j;
                        a[k][1] = i;
                        k++;
                        temp = s[j];
                        s[j] = t[i];
                        t[i] = temp;
                        break;
                    }
                }
            }
        }
        int c=0;
        for(i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                c++;
            }
        }
        if(c>0)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        cout << k << "\n";
        for(i=0;i<k;i++)
        {
            cout << a[i][0]+1 << " " << a[i][1]+1 << "\n";
        }
        }
    }
}
