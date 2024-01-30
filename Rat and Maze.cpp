// Only For Right and Down
#include <bits/stdc++.h>
using namespace std;
const int n=4;
void solver(vector<vector<char>> &ans,int arr[n][n],int r,int c,vector<char> &t){
    if(r<0 or c<0 or r>=n or c>=n or arr[r][c]==1) return;
    if(r==n-1 and c==n-1){
        ans.push_back(t);
        return;
    }
    t.push_back('R');
    solver(ans,arr,r,c+1,t);
    t.pop_back();
    t.push_back('D');
    solver(ans,arr,r+1,c,t);
    t.pop_back();
}
int main() {
	// your code goes here
	int arr[n][n];
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++) cin>>arr[i][j];
	}
	vector<char>t;
	vector<vector<char>>ans;
	solver(ans,arr,0,0,t);
	for(int i=0;i<ans.size();i++){
	    for(int j=0;j<ans[i].size();j++){
	        cout<<ans[i][j];
	    }
	    cout<<"\n";
	}
}
