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

    char ordinal[6000][2];

    int main(){
        //read(in);
        for(int z=1; z<5843; z++){
            if(z%100==11){
                strcpy(ordinal[z], "th");
            }

            else if(z%100==12){
                strcpy(ordinal[z], "th");
            }

            else if(z%100==13){
                strcpy(ordinal[z], "th");
            }

            else if(z%100==14){
                strcpy(ordinal[z], "th");
            }

            else if(z%10==1){
                strcpy(ordinal[z], "st");
            }

            else if(z%10==2){
                strcpy(ordinal[z], "nd");
            }

            else if(z%10==3){
                strcpy(ordinal[z], "rd");
            }

            else{
                strcpy(ordinal[z], "th");
            }
        }

        int humble[5843];

        int n;
        int pos5, pos2, pos3, pos7;
        pos2=0;
        pos3=0;
        pos5=0;
        pos7=0;

        humble[0]=1;

        for(int z=1; z<5842; z++){
            humble[z]=min(min(2*humble[pos2], 3*humble[pos3]), min(5*humble[pos5], 7*humble[pos7]));

            if(humble[z]==2*humble[pos2])
                pos2++;
            if(humble[z]==3*humble[pos3])
                pos3++;
            if(humble[z]==5*humble[pos5])
                pos5++;
            if(humble[z]==7*humble[pos7])
                pos7++;
        }

        int a;

        while(scanf("%d", &a) && a){
            printf("The %d%c%c humble number is %d.\n", a, ordinal[a][0], ordinal[a][1], humble[a-1]);
        }

        return 0;
    }
