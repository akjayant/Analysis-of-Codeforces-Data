#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string string;
        cin>>string;
        int max,i;
        for(i=0;i<string.size();i++)
        {
            if(string[i]=='1')
                break;
        }
        if(i==string.size())
        {
            cout<<n<<"\n";
            continue;
        }
        else
            max=fmax(2*(i+1),2*(n-i));
        for(i=string.size()-1;i>=0;i--)
        {
            if(string[i]=='1')
                break;
        }
        max=fmax(max,fmax(2*(i+1),2*(n-i)));
        cout<<max<<"\n";
    }
    return 0;
}