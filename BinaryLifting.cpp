// Binary Lifting template 
class BinaryLifting
{
    public:
    vector<vector<int> > store;
    vector<int> depth;
    BinaryLifting(vector<vector<int> > &v)
    {
        store.assign(v.size(),vector<int>(30,-1));
        depth.assign(v.size(),0);
        dfs(0,-1,v);
        dept(0,-1,0,v);
        markAncestors();
    }
    void markAncestors()
    {
        rep(i,1,30)
        {
            rep(j,0,store.size())
            {
                int par= store[j][i-1];
                if(par==-1) continue;
                store[j][i]=store[par][i-1];
               // cout<<store[j][i]<<" ";
            }
           // cout<<endl;
        }
    }
    void dept(int sv,int parent,int dep,vector<vector<int> > &v)
    {
        depth[sv]=dep;
        for(auto it:v[sv])
        {
            if(it!=parent)  
                dept(it,sv,dep+1,v);
        }
        return;
    }
    void dfs(int sv,int parent, vector<vector<int> > &v)
    {
        store[sv][0]=parent;
        for(auto it:v[sv])
        {
            if(it!=parent) dfs(it,sv,v);
        }
    }
    int findLCA(int u,int v)
    {
        int x=depth[u];
        int y=depth[v];
        if(x>y) swap(u,v);
        int diff=abs(x-y);
        rep(i,0,30)
        {
            if(diff & (1<<i)) v=store[v][i];
        }
        //cout<<diff<<" "<<u<<" "<<v<<endl;
        rev(i,30,0)
        {
            x=store[u][i];
            y=store[v][i];
            if(x==y) continue;
            u=x,v=y;
        }
        return store[u][0];
    }
};
