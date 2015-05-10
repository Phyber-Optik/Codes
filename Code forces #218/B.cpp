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

    using namespace std;

    int gcd (int n1, int n2) {
        return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
    }

    int main(){
        int a, b;
        while(scanf("%d %d", &a, &b)!=EOF){
            int step=0;
            if(a==b)
                printf("0\n");
            else{
                int flag, f=1;
                int g=gcd(a, b);
                while(a!=g){
                    flag=0;
                    if(a%5==0 && (a/5)%g==0){
                        a=a/5;
                        step++;
                        flag=1;
                    }

                    else if(a%3==0 && (a/3)%g==0){
                        a=a/3;
                        step++;
                        flag=1;
                    }

                    else if(a%2==0 && (a/2)%g==0){
                        a=a/2;
                        step++;
                        flag=1;
                    }

                    //cout<<a<<endl;
                    if(flag==0){
                        f=0;
                        break;
                    }
                }

                while(b!=g){
                    flag=0;
                    if(b%5==0 && (b/5)%g==0){
                        b=b/5;
                        step++;
                        flag=1;
                    }

                    else if(b%3==0 && (b/3)%g==0){
                        b=b/3;
                        step++;
                        flag=1;
                    }

                    else if(b%2==0 && (b/2)%g==0){
                        b=b/2;
                        step++;
                        flag=1;
                    }

                    //cout<<b<<endl;

                    if(flag==0){
                        f=0;
                        break;
                    }
                }

                if(f==0)
                    printf("-1\n");
                else
                    printf("%d\n", step);
            }
        }
        return 0;
    }
