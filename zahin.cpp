#include<bits/stdc++.h>
#define ll long long int
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define slf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define INF 99999999
#define pii pair<int,int>
#define pb push_back
#define MAX 1001
int Set(int n,int pos) {return n | (1<<pos);}
int Reset(int n,int pos){return n & ~(1<<pos);}
int Check(int n,int pos){return n & (1<<pos);}
using namespace std;
vector<int>factor[MAX];
int s,d,dis[MAX];
bool vis[MAX];
void factorize(int n)
{
    int z=n;
    if(n%2==0)
    {
        factor[z].pb(2);
        //cout<<"2"<<endl;
        while(n%2==0)
        {
            n/=2;
        }
    }
    int lim=sqrt(n);
    for(int i=3;i<=lim;i+=2)
    {
        if(n%i==0)
        {
            factor[z].pb(i);
            //cout<<i<<endl;
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>2)
        factor[z].pb(n);
}
int solve()
{
    for(int i=0;i<=d;i++)
        factor[i].clear();
    memset(vis,false,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(!factor[u].size())
        {
            factorize(u);
        }
        for(int i=0;i<factor[u].size();i++)
        {
            if(factor[u][i]==u)
                continue;
            int v=u+factor[u][i];
            if(vis[v]==false && v<=d)
            {
                vis[v]=true;
                dis[v]=dis[u]+1;
                if(v==d)
                    return dis[v];
                q.push(v);
            }
        }
    }
    return -1;
}
int main()
{
    freopen("in.txt","r", stdin);
    int t,T=0;
    sd(t);
    while(t--)
    {
        sd(s); sd(d);
        printf("Case %d: %d\n",++T,solve());
    }
    return 0;
}