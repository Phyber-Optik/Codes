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
    #define MAX 100000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;

    int main(){
        int N;
        int a[MAX]={0}, b[MAX]={0};

        while(scanf("%d",&N)!=EOF){
            for(int i=0; i<N; i++){
                scanf("%d %d", &a[i], &b[i]);
            }

            bool p[N], q[N];
            mem(p, false);
            mem(q, false);

            for(int z=0; z<=N/2-1; z++){
                p[z]=true;
                q[z]=true;
            }

            int flag, i=0, j=0, count=0;

            if(a[i]>b[i]){
                flag=2;
            }

            else{
                flag=1;
            }

            while(1){
                //cout<<"flag="<<flag<<endl;
                if(flag==2){
                    q[j]=true;
                    j++;

                    if(b[j]>a[i]){
                        flag=1;
                    }

                    else{
                        flag=2;
                    }
                }

                else{
                    p[i]=true;
                    i++;

                    if(b[j]>a[i]){
                        flag=1;
                    }

                    else{
                        flag=2;
                    }
                }

                count++;
                if(count==N){
                    break;
                }
            }

            for(int x=0; x<N; x++){
                printf("%d", p[x]);
            }

            printf("\n");

            for(int x=0; x<N; x++){
                printf("%d", q[x]);
            }

            printf("\n");
        }
        return 0;
    }
