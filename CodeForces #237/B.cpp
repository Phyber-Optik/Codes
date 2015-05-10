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
        double a, d;
        int n;
        while(scanf("%lf %lf %d", &a, &d, &n)!=EOF){
            double total_d=(double)n*d+0.5;
            int x=(int)ceil(d/a);
            double c1=fmod(d, a), c2=0;
            //cout<<x<<endl;
            while(n--){
                cout<<x<<endl;
                if(x==1){
                    c2=0;
                    c1=fmod(c1, a);
                    printf("%lf %lf\n", c1, c2);
                    c1+=d;
                    if(c1<=a){
                        x=1;
                    }

                    else{
                        c2=c1;
                        x=2;
                    }
                }

                else if(x==2){
                    c1=a;
                    c2=fmod(c1, a);

                    printf("%lf %lf\n", c1, c2);
                    c2=c2+d;
                    if(c2<=a){
                        x=2;
                    }
                    else{
                        c1=c2;
                        x=3;
                    }
                }

                else if(x==3){
                    c2=a;
                    c1=fmod(c1, c2);
                    c1=a-c1;

                    printf("%lf %lf\n", c1, c2);
                    c1=c1+d;
                    if(c1<=a){
                        x==3;
                    }
                    else{
                        c2=c1;
                        x=4;
                    }
                }

                else{
                    c1=0;
                    c2=fmod(c2, a);
                    c2=a-c2;

                    printf("%lf %lf\n", c1, c2);
                    c2=c2+d;

                    if(c2<=a){
                        x=4;
                    }

                    else{
                        c1=c2;
                        x=1;
                    }
                }
            }
        }
        return 0;
    }
