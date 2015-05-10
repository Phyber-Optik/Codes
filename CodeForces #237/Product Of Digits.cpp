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
        //freopen("in.txt", "r", stdin);
        //read(in);
        int N;
        vector<int>digit;
        cin>>N;

        while(N--){
            int n;
            cin>>n;
            if(n==1)
                printf("1\n");

            else{
                int flag=0;
                int p=n;
                for(int i=9; i>=2 && n; i--){
                    //cout<<i<<" "<<n<<endl;
                    while(n){
                        if(n%i==0){
                            flag=1;
                            digit.pb(i);
                            n=n/i;
                        }

                        else
                            break;
                    }
                }
                if(n>1){
                    flag=0;
                }
                if(flag==0){
                    printf("-1\n");
                }

                else{
                    for(int i=digit.size()-1; i>=0; i--){
                        printf("%d", digit[i]);
                    }
                    printf("\n");
                }
            }

            digit.clear();
        }
        return 0;
    }
