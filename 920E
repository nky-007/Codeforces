#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(false); cin.tie(0);
//const int M=1e9+7;
int M;
ll powmod(ll a,ll b) {ll res=1;a%=M; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res%M;}/* a^b%M */
const int N=2e5+10;
set<int>v[N];
queue<int>qq;
int c;
bool mark[N];
void dfs(int source)
{
    mark[source]=1;
    c++;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        source=q.front();
        q.pop();
        int loop=qq.size();
        while(loop--)
        {
            int u=qq.front();
            qq.pop();
            if(v[source].find(u)==v[source].end())
                mark[u]=1,c++,q.push(u);
            else qq.push(u);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].insert(b);
        v[b].insert(a);
    }
    for(int i=1;i<=n;++i)qq.push(i);
    vector<int>ans;
    for(int i=1;i<=n;++i)
    {
        if(!mark[i])
        {
            int id=qq.front();
            qq.pop();
            c=0;
            dfs(id);
            ans.pb(c);
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
