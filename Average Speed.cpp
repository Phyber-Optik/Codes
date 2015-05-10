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

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;

    int main(){
        //read(in);
        int hh, mm, ss;
        double distance=0;
        int ph=0, pm=0, ps=0, psp=0;
        string str;

        while(getline(cin, str)){
            hh=(str[0]-'0')*10+(str[1]-'0');
            mm=(str[3]-'0')*10+(str[4]-'0');
            ss=(str[6]-'0')*10+(str[7]-'0');
            //cout<<hh<<" "<<mm<<" "<<ss<<endl;

            //cout<<str.size()<<endl;
            string s;
            int speed;

            if(str.size()>8){
                int pos=9;
                while(str[pos]){
                    s.push_back(str[pos]);
                    pos++;
                }
                speed=atoi(s.c_str());
                //cout<<"speed="<<speed<<endl;
            }


            double d;
            if(str.size()>8){
                d=psp*(ss-ps+60*(mm-pm)+3600*(hh-ph))/3600.0;
                //cout<<"d="<<d<<endl;
                //d=round(d);
                distance+=d;

                psp=speed;
                ps=ss;
                ph=hh;
                pm=mm;
            }

            else{
                //cout<<"previous speed="<<psp<<endl;
                d=psp*(ss-ps+60*(mm-pm)+3600*(hh-ph))/3600.0;
                distance+=d;

                cout<<str;
                printf(" %.2lf km\n", distance);

                ps=ss;
                ph=hh;
                pm=mm;
            }

            str.clear();
            s.clear();
        }
        return 0;
    }
