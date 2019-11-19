#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct node
{
    int width,height;
    long long sum;
};
int num[100010];
node inf[100010],inf0[100010];

void get_inf(int n)
{
    int w = 1,tim = 0;
    num[n+1] = -1; num[0] = -1;
    for(int i = 2; i <= n; i++)
    {
        if(num[i]!=num[i-1])
        {
            inf[++tim].height = num[i]-num[i-1];
            inf[tim].width = w;
            inf[tim].sum = 1LL*inf[tim].height*inf[tim].width;
            w++;
        }
        else
            w++;
    }
    w = 1; tim = 0;
    for(int i = n; i >= 2; i--)
    {
        if(num[i]!=num[i-1])
        {
            inf0[++tim].height = num[i]-num[i-1];
            inf0[tim].width = w;
            inf0[tim].sum = 1LL*inf0[tim].height*inf0[tim].width;
            w++;
        }
        else
            w++;
    }
}

int get_ans(int n,long long k)
{
    int low = num[1],high = num[n];
    long long t = k;
    int cnt1 = 1,cnt2 = 1;
    while(low < high&&t > 0)
    {
        //cout<<cnt1<<' '<<cnt2<<' '<<t<<endl;
        if(inf[cnt1].width <= inf0[cnt2].width)
        {
            if(t >= inf[cnt1].sum)
            {
                t -= inf[cnt1].sum;
                low += inf[cnt1].height;
                cnt1++;
            }
            else if(t < inf[cnt1].sum)
            {
                low += t/inf[cnt1].width;
                t = 0;
                cnt1++;
            }
        }
        else if(inf[cnt1].width > inf0[cnt2].width)
        {
            if(t >= inf0[cnt2].sum)
            {
                t -= inf0[cnt2].sum;
                high -= inf0[cnt2].height;
                //cout<<inf0[cnt2].height<<"dd"<<cnt2<<endl;
                cnt2++;
            }
            else if(t < inf0[cnt2].sum)
            {
                high -= t/inf0[cnt2].width;
                t = 0;
                cnt2++;
            }
        }
    }
    return high-low;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    long long k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
    {
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    get_inf(n);
    /*for(int i = 1; i <= 5; i++)
    {
        cout<<inf[i].height<<' '<<inf[i].width<<endl;
    }
    for(int i = 1; i <= 5; i++)
    {
        cout<<inf0[i].height<<' '<<inf0[i].width<<endl;
    }*/
    int ans = get_ans(n,k);
    cout<<ans<<endl;
    return 0;
}
