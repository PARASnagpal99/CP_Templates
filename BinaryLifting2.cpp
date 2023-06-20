// To find The kth Ancestor 
int kthParent(int x, int k, vector<vector<int>>& parents){
    int n = parents[0].size();
    for(int i = 0; i <= log2(n); i++){
        if(k & (1 << i)){
            x = parents[i][x];
            if(x == -2)
                break;
        }
    }
    
 return x ;
}

// Assigning the parent to first level 
void dfs(int current, vector<vector<int>>& edges, int parent, vector<int>& firstParents){
    firstParents[current] = parent;
    for(auto neighbour: edges[current]){
        if(neighbour != parent)
            dfs(neighbour, edges, current, firstParents);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<vector<int>> parents(log2(n) + 1, vector<int>(n, -1));
    dfs(0, edges, -1, parents[0]);

    // Binary Lifting 
    for(int k = 1; k <= log2(n); k++){
        for(int i = 0; i < n; i++){
            int intermediate = parents[k - 1][i];
            if(intermediate != -1)
                parents[k][i] = parents[k - 1][intermediate];
        }
    }
}
