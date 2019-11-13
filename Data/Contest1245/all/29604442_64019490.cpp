#include<iostream>


using namespace std;

string Bob;
int t;
int n;
int a, b, c;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>a>>b>>c;
        cin>>Bob;
        int B_R = 0;
        int B_S = 0;
        int B_P = 0;
        for(int i = 0; i < n; ++i)
        {
            if(Bob[i] == 'S')
            {
                B_S++;
            }
            else if(Bob[i] == 'R')
            {
                B_R++;
            }
            else
            {
                B_P++;
            }
        }
        if(min(a, B_S) + min(b, B_R) + min(c, B_P) >= (n+1) / 2)
        {
            cout<<"YES"<<endl;
            string ans = "";
            for(int i = 0; i < n; ++i)
            {
                if(Bob[i] == 'R')
                {
                    if(b > 0)
                    {
                        ans += 'P';
                        --b;
                        --B_R;
                    }
                    else if(a > B_S)
                    {
                        ans += 'R';
                        --a;
                    }
                    else
                    {
                        ans += 'S';
                        --c;
                    }
                }
                else if(Bob[i] == 'P')
                {
                    if(c > 0)
                    {
                        ans += 'S';
                        --c;
                        --B_P;
                    }
                    else if(a > B_S)
                    {
                        ans += 'R';
                        --a;
                    }
                    else
                    {
                        ans += 'P';
                        --b;
                    }
                }
                else
                {
                    if(a > 0)
                    {
                        ans += 'R';
                        --a;
                        --B_S;
                    }
                    else if(b > B_R)
                    {
                        ans += 'P';
                        --b;
                    }
                    else
                    {
                        ans += 'S';
                        --c;
                    }
                }
            }
            cout<<ans<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
