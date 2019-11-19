#include <bits/stdc++.h>
using namespace std;
int b[501];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s='@'+s;
    int i,j,k;
    int ans=0;
    pair<int,int>p=make_pair(1,1);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            int c=0,d=0;
            string r=s;
            swap(r[i],r[j]);
            stack<int>st;
            memset(b,0,sizeof(b));
            b[0]=0;
            for(k=1;k<=n;k++)
            {
                if(r[k]==')')
                {
                    if(st.empty())
                    {
                        d++;
                        c=0;
                    }
                    else
                    {
                        st.pop();
                        if(st.empty())
                        {
                            c++;
                        }
                    }
                }
                else
                {
                    st.push(k);
                }
                b[k]=c;
            }
            int g=st.size();
            int anss=n+1;
            int e=0;
            while(!st.empty())
            {
                e++;
                int g=st.top();
                st.pop();
                anss=min(anss,g);
            }
            c=b[anss-1];
            if(e>0)
                c++;
            if(g==d)
            {
                if(ans<c)
                {
                    ans=c;
                    p=make_pair(i,j);
                }
            }
        }
    }
    cout<<ans<<endl;
    cout<<p.first<<" "<<p.second<<endl;
}
