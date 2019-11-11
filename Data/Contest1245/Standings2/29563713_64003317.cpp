#include<bits/stdc++.h>
using namespace std;
char ch[1000],out[1000];

queue < int > q;


int main()
{
    int test,t,i,j,k,a,b,c,aa,bb,cc,x,y,z,n;
    cin>>test;
    for(t=1; t<=test; t++)
    {
        scanf("%d",&n);
        cin>>a>>b>>c;
        scanf("%s", ch);
        aa=a;
        bb=b;
        cc=c;
        z=0;
        for(i=0; i<n; i++)
        {
            if(ch[i]=='R')
            {
                if(bb>0)
                {
                    bb--;
                    out[i]='P';
                    z++;
                }
                else
                {
                    q.push(i);
                }
            }
            else if(ch[i]=='P')
            {
                if(cc>0)
                {
                    cc--;
                    out[i]='S';
                    z++;
                }
                else
                {
                    q.push(i);
                }
            }
            else
            {
                if(aa>0)
                {
                    aa--;
                    out[i]='R';
                    z++;
                }
                else
                {
                    q.push(i);
                }
            }
        }
        //cout<<z<<endl;
        while(!q.empty())
        {
            a=q.front();
            q.pop();
            if(aa>0)
            {
                aa--;
                out[a]='R';
            }
            else if(bb>0)
            {
                bb--;
                out[a]='P';
            }
            else{
                cc--;
                out[a]='S';
            }
        }
        out[n]='\0';
        if(z*2>=n)
        {
            printf("YES\n%s\n",out);
        }
        else
        {
            printf("NO\n");
        }


    }
}
