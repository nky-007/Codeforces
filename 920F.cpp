#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(false); cin.tie(0);
const int M=1e9+7;
ll powmod(ll a,ll b) {ll res=1;a%=M; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res%M;}/* a^b%M */
const int N=3e5+10;
ll a[N];
struct node
{
    ll maxi,val;
}segt[5*N];
ll divisor[1000001];
void construct(int low,int high,int pos)
{
    if(low==high)
    {
        segt[pos].val=a[low];
        segt[pos].maxi=a[low];
        return;
    }
    int mid=(low+high)/2;
    construct(low,mid,2*pos+1);
    construct(mid+1,high,2*pos+2);
    segt[pos].val=(segt[2*pos+1].val+segt[2*pos+2].val);
    segt[pos].maxi=max(segt[2*pos+1].maxi,segt[2*pos+2].maxi);
}
void update(int l,int r,int low,int high,int pos)
{
    if(low>high)return;

    if(l>high||r<low)return;
    if(l<=low&&r>=high)
    {
        if(segt[pos].maxi<=2)return ;
        if(low==high)
        {
            segt[pos].val=divisor[segt[pos].val];
            segt[pos].maxi=segt[pos].val;
            return ;
        }
    }
    int mid=(low+high)/2;
    update(l,r,low,mid,2*pos+1);
    update(l,r,mid+1,high,2*pos+2);
    segt[pos].val=(segt[2*pos+1].val+segt[2*pos+2].val);
    segt[pos].maxi=max(segt[2*pos+1].maxi,segt[2*pos+2].maxi);
}
ll query(int l,int r,int low,int high,int pos)
{
    if(low>high)return 0;

    if(l>high||r<low)return 0;
    if(l<=low&&r>=high)
        return segt[pos].val;
    int mid=(low+high)/2;
    return (query(l,r,low,mid,2*pos+1)+(query(l,r,mid+1,high,2*pos+2)));
}
int main()
{
    for(int i=1;i<=1000000;++i)
    {
            for(int j=i;j<=1000000;j+=i)
            {
                divisor[j]++;
            }
    }
  //  for(int i=1;i<=10;++i)cout<<divisor[i]<<" ";
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)scanf("%lld",&a[i]);
    construct(0,n-1,0);
    while(m--)
    {
        int t;
        scanf("%d",&t);
        if(t&1)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            update(l-1,r-1,0,n-1,0);
        }
        else
        {
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",query(l-1,r-1,0,n-1,0));
        }
    }
    return 0;
}
