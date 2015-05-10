    #include<cstdio>
    #include<iostream>
    #include<cstring>
    #include<cmath>
    #include<cstdlib>
    #include<cctype>
    #include<vector>
    #include<queue>
    #include<fstream>
    #include<sstream>
    #include<set>
    #include<climits>
    #include<map>
    #include<algorithm>

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;

    int main(){
        int n, k;
        while(scanf("%d %d", &n, &k)!=EOF){
            int a[1000];
            for(int i=0; i<n; i++){
                scanf("%d", &a[i]);
            }

            int dif[1000];
            mem(dif, 0);
            dif[0]=a[0];



            for(int i=2; i<n; i++){
                dif[i]=a[i]-a[i-1];
            }


            int shd[1000];
            for(int j=0; j<n; j++){

                int cnt=0;
                shd[j]=a[j];
                int t=k;
                for(int i=0; i<n; i++){
                    shd[i]=t;
                    if(shd[i]!=a[i])
                        cnt++;
                    t+=k;
                }
                cout<<cnt<<endl;
            }

            for(int i=0; i<n; i++){
                //cout<<dif[i]<< " "<<shd[i]<<endl;
                int temp=shd[i]-a[i];
                if(temp!=0){

                    if(temp<0){
                        cout<<"- ";
                        temp*=-1;
                    }

                    else
                        cout<<"+ ";
                    cout<<i+1<<" ";
                    cout<<temp<<endl;
                }
            }
        }
        return 0;
    }
