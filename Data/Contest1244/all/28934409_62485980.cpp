#include <bits/stdc++.h>

using namespace std;
long long a,b,c[100010],l,p,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    for(int i=0; i<a; i++)
    {
        cin>>c[i];
    }
    sort(c,c+a);
    l=0;
    p=a-1;
    while(l<a-1&&c[l]==c[l+1])
    {
        l++;
    }
    while(l>0&&c[p]==c[p-1])
    {
        p--;
    }
    k=b;
    while(l<p)
    {
        if(l+1<a-p)
        {
            if((c[l+1]-c[l])*(l+1)>k)
            {
                c[l]+=(k/(l+1));
                cout<<c[p]-c[l]<<"\n";
                return 0;
            }else
            {
                k-=(c[l+1]-c[l])*(l+1);
                c[l]=c[l+1];
            }
        }
        else
        {
             if((c[p]-c[p-1])*(a-p)>k)
            {
                c[p]-=(k/(a-p));
                cout<<c[p]-c[l]<<"\n";
                return 0;
            }else
            {
                k-=(c[p]-c[p-1])*(a-p);
                c[p]=c[p-1];
            }
        }

        while(l<a-1&&c[l]==c[l+1])
        {
            l++;
        }
        while(p>0&&c[p]==c[p-1])
        {
            p--;
        }
    }
    cout<<0<<endl;
    return 0;
}
