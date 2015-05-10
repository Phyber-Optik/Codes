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
    #define si 32100

    vector<int> prime;
    bool status[32100];

    void sieve(){
        int i, j;
        for(i=0; i<si; i++){
            status[i]=false;
        }

        int sq=sqrt(si);

        for(i=4; i<=si; i+=2){
            status[i]=true;
        }

        for(i=3; i<=sq; i+=2){
            if(status[i]==false){
                for(j=2*i; j<=si; j+=i){
                    status[j]=true;
                }
            }
        }

        status[1]=true;

        for(int z=1; z<=si; z++){
            if(status[z]==false){
                prime.push_back(z);
            }
        }
    }

    int main(){
        sieve();
        vector<int>dis;

        for(int i=0; i<prime.size()-1; i++){
            dis.push_back(prime[i+1]-prime[i]);
        }


        vector<int> v[200];
        int k=0;

        for(int i=1; i<dis.size(); ){
            if(dis[i]==dis[i+1]){
                int cur_dis=dis[i];
                v[k].push_back(prime[i]);
                v[k].push_back(prime[i+1]);
                v[k].push_back(prime[i+2]);

                i=i+2;
                while(1){
                    if(dis[i]==cur_dis){
                        v[k].push_back(prime[i+1]);
                        i++;
                    }

                    else{
                        break;
                    }
                }

                k++;
            }

            else
                i++;
        }

        int c, d;
        while(scanf("%d %d", &c, &d) && (c|d)){
            if(c>d){
                swap(c, d);
            }
            for(int i=0; i<163; i++){
                if(v[i][0]>=c && v[i][v[i].size()-1]<=d){
                    printf("%d", v[i][0]);
                    for(int j=1; j<v[i].size(); j++){
                        printf(" %d", v[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        return 0;
    }
