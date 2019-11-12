#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

struct da
{
    int a,b;
};

da date[200];
int pos;

void judge(string s1,string s2,int n)
{
    for (int i=0;i<n;i++)
    {
        if (s1[i]!=s2[i])
        {
            int flag=0;
            for (int j=i+1;j<n;j++)
            {
                if (s2[j]==s2[i])
                {
                    date[pos].a=i;
                    date[pos].b=j;
                    pos++;
                    s2[j]=s1[i];
                    flag=1;
                    break;
                }
                if (s1[j]==s2[i])
                {
                    date[pos].a=j;date[pos].b=j;pos++;
                    date[pos].a=i;date[pos].b=j;pos++;
                    s1[j]=s2[j];
                    s2[j]=s1[i];
                    flag=1;
                    break;
                }
            }
            if (flag==0)
            {
                cout<<"NO\n";
                return ;
            }
        }
    }
    cout<<"YES\n";
    cout<<pos<<endl;
    for (int i=0;i<pos;i++)
        cout<<date[i].a+1<<" "<<date[i].b+1<<endl;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        string s1,s2;
        cin>>n>>s1>>s2;
        pos=0;
        memset(date,0,sizeof(date));
        judge(s1,s2,n);
    }


    return 0;
}
