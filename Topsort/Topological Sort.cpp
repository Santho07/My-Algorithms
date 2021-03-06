#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mx 100
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


bitset<mx> vis;
vi adj[mx], ts;

void dfs2(int u){
    vis[u] = 1;
    int l = adj[u].size();
    for(int j=0; j<l; j++){
        int v = adj[u][j];
        if(vis[v]==0) dfs2(v);
    }
    ts.pb(u); //this is the only change
}
int main()
{
    ts.clear();
    vis.reset(); //setting all node visiting status to 0

    int n, i, j, a, b;
    cin>>n;
    for(i=0; i<n; i++) adj[i].clear();
    for(i=0; i<n; i++){
        cin>>a>>b;
        adj[a].pb(b);
    }
    for(int v=0; v<n; v++){
        for(i=0; i<n; i++){
            if(vis[i]==0) dfs2(i); //calling dfs for every node
        }
        for(i=(int)ts.size() - 1; i>=0; i--){
            printf(" %d", ts[i]);
        }
    }
    printf("\n");
}
