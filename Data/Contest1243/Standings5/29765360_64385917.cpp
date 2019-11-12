#include <iostream>

using namespace std;
int t,n,diff,idx[10100],top=0;
char str1[10100],str2[10100];
int main()
{
    cin>>t;
    while(t--)
    {
        fill(str1,str1+10000,0);
        fill(str2,str2+10000,0);
        fill(idx,idx+10000,0);
        diff=0;
        top=0;
        cin>>n;
        scanf("%s",str1);
        scanf("%s",str2);
        for(int i=0;i<n;i++)
        {
            if(str1[i]!=str2[i])
            {
                diff++;
                idx[top]=i;
                top++;
            }
        }
        if(diff==0)
        {
            cout<<"Yes"<<endl;
        }
        else if(diff==2 && str1[idx[0]]==str1[idx[1]] && str2[idx[0]]==str2[idx[1]])
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
