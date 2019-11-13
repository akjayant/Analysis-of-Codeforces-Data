#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

char sn[11000];


int main()
{
    int t,n,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        cin>>sn;
        int R = 0,P = 0,S = 0;
        int l = strlen(sn);
        for(i = 0;i<l;i++)
        {
            if(sn[i] == 'R') R++;
            else if(sn[i] == 'P') P++;
            else if(sn[i] == 'S') S++;
        }
        int num = min(a,S)+min(b,R)+min(c,P);
        if(num>=(n+1)/2)
        {
            cout<<"YES"<<endl;
            int aS = a-S;
            int bR = b-R;
            int cP = c-P;
            for(i = 0;i<l;i++)
            {
                if(sn[i] == 'R')
                {
                    if(b>0)
                    {
                        cout<<'P';
                        b--;
                    }
                    else
                    {
                        if(aS>0)
                        {
                            cout<<'R';
                            a--;
                            aS--;
                        }
                        else
                        {
                            cout<<'S';
                            c--;
                            cP--;
                        }
                    }
                }
                else if(sn[i] == 'P')
                {
                    if(c>0)
                    {
                        cout<<'S';
                        c--;
                    }
                    else
                    {
                        if(aS>0)
                        {
                            cout<<'R';
                            a--;
                            aS--;
                        }
                        else
                        {
                            cout<<'P';
                            b--;
                            bR--;
                        }
                    }

                }
                else
                {

                    if(a>0)
                    {
                        cout<<'R';
                        a--;
                    }
                    else
                    {
                        if(bR>0)
                        {
                            cout<<'P';
                            b--;
                            bR--;
                        }
                        else
                        {
                            cout<<'S';
                            c--;
                            cP--;
                        }
                    }
                }
            }
            cout<<endl;
        }
        else cout<<"NO"<<endl;

    }
    return 0;
}
