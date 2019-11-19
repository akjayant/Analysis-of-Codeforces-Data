#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long int num;
    cin>>num;
    long long int xx = sqrt(num);
    long long int div1 = -1;
    for(long int i = 2;i<=xx;i++)
    {
        if(((num%i)==0)&&div1==-1)
        {
            while((num%i)==0)
            {
                num = num/i;
            }
            div1 = i;
        }
        else if(((num%i)==0)&&div1!=-1)
        {
            cout<<"1"<<endl;
            return 0;
        }
    }
    if(num>1&&div1!=-1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    else if(div1==-1)
    {
        cout<<num<<endl;
        return 0;
    }
    else
    {
        cout<<div1<<endl;
        return 0;
    }
    return 0;
}
