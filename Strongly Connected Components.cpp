// GFG 
// Kosaraju's Algorithm
void dfs(int node , vector<int> &vis,stack<int> &st , vector<vector<int>> &adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs(it , vis, st , adj);
	        }
	    }
	    st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(V,0);
        vector<vector<int>> revadj(V,vector<int>());
        for(int i = 0 ; i < adj.size() ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                revadj[adj[i][j]].push_back(i);
            }
        }
        stack<int> st;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int> vist(V,0);
        int ans = 0;
        stack<int> s;
        while(!st.empty()){
            if(vist[st.top()] == 0){
                ans++;
                dfs(st.top(),vist,s,revadj);
            }
            st.pop();
        }
        return ans;
    }
