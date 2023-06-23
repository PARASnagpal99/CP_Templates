int timer = 0 ;
vector<int> inTime , outTime ;
// Assigning the parent to first level 
void dfs(int current, vector<vector<int>>& edges, int parent, vector<int>& firstParents){
    firstParents[current] = parent;
    inTime[current] = timer++;
    for(auto neighbour: edges[current]){
        if(neighbour != parent)
            dfs(neighbour, edges, current, firstParents);
    }
    outTime[current] = timer++;
}


bool isAncestor(int u , int v){
     return (inTime[u] <= inTime[v] && outTime[u] >= outTime[v]);
}


// Finding LCA 
int LCA(int a , int b , vector<vector<int>>&parents){
    if(isAncestor(a,b)) return a ;
    
    if(isAncestor(b,a)) return b ;
    
    int n = inTime.size() ;

    for(int k=log2(n) + 1 ; k >= 0 ; k--){
        int parent_a = parents[k][a];
        if(!isAncestor(parent_a,b)){
            a = parent_a ;
        }
    }
    return parents[0][a];
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
    
    timer = 0 ;
    inTime.resize(n);
    outTime.resize(n);
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














