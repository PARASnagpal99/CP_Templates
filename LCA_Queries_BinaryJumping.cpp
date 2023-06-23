// To find The kth Ancestor 
int kthParent(int x, int k, vector<vector<int>>& parents){
    int n = parents[0].size();
    for(int i = 0; i <= log2(n); i++){
        if(k & (1 << i)){
            x = parents[i][x];
            if(x == -1)
                break;
        }
    }
    
 return x ;
}
 
vector<int> level;
// Assigning the parent to first level 
void dfs(int current, vector<vector<int>>& edges, int parent, vector<int>& firstParents , int d){
    firstParents[current] = parent;
    level[current] = d;
    for(auto neighbour: edges[current]){
        if(neighbour != parent)
            dfs(neighbour, edges, current, firstParents,d+1);
    }
}
 
 
 
// Finding LCA 
int LCA(int x , int y , vector<vector<int>>&parents){
    
    // Lifing 
    if(level[x] > level[y]) x = kthParent(x,level[x]-level[y],parents);
    
    if(level[y] > level[x]) y = kthParent(y,level[y]-level[x],parents);
    
    if(x == y) return x ;
    
    int n = level.size();
    
    for(int k = log2(n) ; k >= 0  ; k--){
        int parent_x = parents[k][x] ;
        int parent_y = parents[k][y] ;
        
        if(parent_x!=-1 && parent_y!=-1 && parent_x!=parent_y){
            x = parent_x ;
            y = parent_y ;
        }
        
    }
   
    return parents[0][x];
}
 
 
 
 
void solve(){
    int n , q ;
    cin >> n >> q ;
    
    vector<vector<int>> edges(n, vector<int>());
    
    for(int i = 1; i <= n - 1; i++){
        int u ;
        cin >> u ;
        u--;
        edges[u].push_back(i);
        edges[i].push_back(u);
    }
    
    vector<vector<int>> parents(log2(n) + 1, vector<int>(n, -1));
    
    level.resize(n);
    dfs(0, edges, -1, parents[0] , 0);
 
    // Binary Lifting 
    for(int k = 1; k <= log2(n); k++){
        for(int i = 0 ; i < n; i++){
            int intermediate = parents[k - 1][i];
            if(intermediate != -1)
                parents[k][i] = parents[k - 1][intermediate];
        }
    }
    
    for(int i=0 ; i<q ; ++i){
        int a , b ;
        cin >> a >> b ;
        a--; b--;
        cout << LCA(a,b,parents)+1 << endl ;
    }
    
    
}
 
 
