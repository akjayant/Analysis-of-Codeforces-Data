#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<time.h>
#include<set>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int sum=0;
        while(b>=1&&c>=2)
        {
            sum++;
            b--;c-=2;
        }
        while(a>=1&&b>=2)
        {
            sum++;
            a--;b-=2;
        }
        cout<<3*sum<<endl;
    }
    return 0;
}
