          #include <bits/stdc++.h>
          using namespace std;
          #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
          #define M_PI 3.14159265358979323846
          #define data data_
          #define ff first
          #define ss second

          int main()
          {
          clock_t begin = clock();
          #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin);
          freopen("output.txt", "w", stdout);
          #endif
          tani_nachi_ke  

          int T;
          cin >> T;
          while(T--)
          {
               long long n;
               cin >> n;
               long long a = 0, b = 0;
               for(int i = 0 ;i  < n; i++)
               {
                    long long x;
                    cin >> x;
                    if(x&1)a++;
               }
               long long m;
               cin >> m;
               for(int i = 0; i < m; i++)
               {
                    long long x;
                    cin >> x;
                    if(x&1)
                         b++;
               }

               cout << a*b + (n-a)*(m-b) << '\n';
          }          




          #ifndef ONLINE_JUDGE 
          clock_t end = clock();
          cout<<endl<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
          #endif 
          return 0;
          }