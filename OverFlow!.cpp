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
        string a, b, str;
        char ch;
        while(getline(cin, str)){
            a.clear();
            b.clear();

            if(str.size()==0){
                printf("\n");
            }

            else{
                long long m, n;
                string p, q;

                int pos=0;
                while(str[pos]!=' '){
                    p.push_back(str[pos]);
                    pos++;
                }

                ch=str[pos+1];

                pos+=3;
                while(str[pos]){
                    q.push_back(str[pos]);
                    pos++;
                }

                //cout<<a<<endl;
                //cout<<b<<endl;

                pos=0;
                while(p[pos]=='0' && pos<p.size()-1){
                    pos++;
                }
                while(pos<p.size()){
                    a.push_back(p[pos]);
                    pos++;
                }

                //a.push_back(p[pos]);

                pos=0;
                while(q[pos]=='0' && pos<q.size()-1){
                    pos++;
                }

                while(pos<q.size()){
                    b.push_back(q[pos]);
                    pos++;
                }

                if(a.size()>10 || b.size()>10){
                    int f=1;

                    if((a=="0" || b=="0") && ch=='*'){
                        cout<<p<<" "<<ch<<" "<<q<<endl;

                        if(a.size()>10){
                            printf("first number too big\n");
                        }

                        if(b.size()>10){
                            printf("second number too big\n");
                        }
                        f=0;
                    }

                    if(f==1){
                        cout<<p<<" "<<ch<<" "<<q<<endl;
                        if(a.size()>10){
                            printf("first number too big\n");
                        }

                        if(b.size()>10){
                            printf("second number too big\n");
                        }

                        printf("result too big\n");
                    }
                }

                else{
                    m=atoll(a.c_str());
                    n=atoll(b.c_str());

                    long long result;
                    if(ch=='+')
                        result=m+n;
                    else
                        result=m*n;

                    int flag=1;
                    if(result>INT_MAX){
                        flag=0;
                    }

                    if(flag==1){
                        cout<<p<<" "<<ch<<" "<<q<<endl;

                        if(m>INT_MAX){
                            printf("first number too big\n");
                        }

                        if(n>INT_MAX){
                            printf("second number too big\n");
                        }
                    }

                    else{
                        cout<<p<<" "<<ch<<" "<<q<<endl;
                        if(m>INT_MAX){
                            printf("first number too big\n");
                        }

                        if(n>INT_MAX){
                            printf("second number too big\n");
                        }

                        if(result>INT_MAX){
                            printf("result too big\n");
                        }
                    }
                }
            }
            str.clear();
        }
        return 0;
    }
