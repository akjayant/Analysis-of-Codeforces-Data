#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

char sn[11000];
char tn[11000];
void swap(char &a,char &b)
{
    char t = a;
    a = b;
    b = t;
}
int sp[1100][2];

int main()
{
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s%s",sn,tn);
        int num = 0;
        for(i = 0;i<n;i++)
        {
            if(sn[i]!=tn[i])
            {
                int id = -1;
                for(j = i+1;j<n;j++)
                {

                    //cout<<id<<endl;
                    //cout<<i<<" "<<sn[i]<<" "<<j<<" "<<sn[j]<<endl;
                    if(sn[j] == sn[i])
                    {
                        id = j;
                        //cout<<id<<"**********"<<endl;
                        break;
                    }

                }
                //cout<<id<<"&&&&&&&&&&&"<<endl;
                if(id!=-1)
                {
                    sp[num][0] = j;
                    sp[num++][1] = i;
                    swap(sn[j],tn[i]);

                }
                else
                {
                    for(j = i+1;j<n;j++)
                    {
                        if(tn[j] == sn[i])
                        {
                            id = j;
                            break;
                        }
                    }
                    if(id!=-1)
                    {
                        sp[num][0] = i+1;
                        sp[num++][1] = j;
                        swap(sn[i+1],tn[j]);
                        sp[num][0] = i+1;
                        sp[num++][1] = i;
                        swap(sn[i+1],tn[i]);
                    }
                    else
                    {
                        //cout<<i<<" "<<id<<endl;
                        goto w;
                    }
                }
            }
        }
        cout<<"Yes"<<endl;
        cout<<num<<endl;
        for(i = 0;i<num;i++)
        {
            cout<<sp[i][0]+1<<" "<<sp[i][1]+1<<endl;
        }
        continue;
        w: cout<<"No"<<endl;
        //cout<<sn<<endl<<tn<<endl;
    }
    return 0;
}
