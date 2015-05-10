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
        int p, x;
        while(scanf("%d %d", &p, &x)!=EOF){
            string s;
            int chk=1, found=0;
            if(p==1 && x==1)
                cout<<1<<endl;
            else{
            if(p==1)
                found =0;
            else
            while(chk < 10){
                int flag=1;
                int pos=1;
                int carry=0, prev=chk;

                s.push_back(chk+'0');
                while(pos<p-1){
                    int temp=prev*x+carry;
                    //cout<<temp<<endl;
                    prev=(temp%10);
                    char ch=prev+'0';
                    //cout<<"ch="<<prev<<endl;
                    s.push_back(ch);
                    carry=temp/10;
                    pos++;
                }

                //cout<<carry<<endl;
                if(carry){
                    if(carry*x>9)
                        flag=0;
                    else
                        s.push_back(carry+'0');
                }

                else{
                    if(prev*x>9){
                        flag=0;
                    }

                    else{
                        s.push_back(prev*x+'0');
                    }
                }
                //cout<<flag<<endl;
                //cout<<chk<<" "<<"s="<<s<<endl;

                int f;
                if(flag)
                    f=1;
                else
                    f=0;
                string s2;
                for(int i=1; i<s.size(); i++){
                    s2.push_back(s[i]);
                }

                s2.push_back(s[0]);
                //cout<<"s2="<<s2<<endl;

                if(flag){
                    int i=0, carry=0, k=0;

                    while(i<(p)){
                        int temp=(s[i] -'0')*x+carry;
                        //cout<<temp<<endl;
                        if((temp%10 + '0')!=s2[k]){
                            f=0;
                            break;
                        }
                        carry=temp/10;
                        i++;
                        k++;
                    }
                }
                //cout<<"flag="<<flag<<endl;
                if(s[0]=='0')
                    f=0;
                if(f){
                    int j=s.size();
                    while(j--){
                        cout<<s[j];
                    }

                    cout<<endl;
                    found=1;
                    break;
                }

                s.clear();
                s2.clear();
                chk++;
            }

            if(found==0){
                cout<<"Impossible\n";
            }
            }
        }
        return 0;
    }
