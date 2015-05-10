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
        //read(in);
        int ara[22]={2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79,
        97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
        int n;
        while(scanf("%d", &n) && n){
            if(n>990)
                printf("0\n");
            else{
                int N=n, cnt=0, flag=0;
                while(N){
                    cnt++;
                    N=N/10;
                }
                //cout<<cnt<<endl;
                for(int i=0; ara[i]; i++){
                    if(ara[i]>n && ara[i]<(pow(10, cnt))){
                        printf("%d\n", ara[i]);
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("0\n");
                }
            }
        }
        //cout<<flag<<endl;
        return 0;
    }
