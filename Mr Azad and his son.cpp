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
    int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int notperfect[]={11, 23, 29};
    int main(){
        bool status[32];
        mem(status, false);
        for(int i=0; prime[i]; i++){
            status[prime[i]]=true;
        }

        int chk[32];
        long long perfect[32];
        mem(chk, 0);

        for(int i=2; i<=31; i++){
            if(status[i]==true){
                chk[i]=1;

                if(i!=11 && i!=23 && i!=29){
                    chk[i]=2;
                    perfect[i]=pow(2, i-1)*(pow(2, i)-1);
                }
            }

            //cout<<i<<" "<<chk[i]<<endl;
        }

        int test;
        while(scanf("%d", &test) && test){
            if(chk[test]==0){
                printf("Given number is NOT prime! NO perfect number is available.\n");
            }

            else if(chk[test]==1){
                printf("Given number is prime. But, NO perfect number is available.\n");
            }

            else{
                printf("Perfect: %lld!\n", perfect[test]);
            }
        }

        return 0;
    }
