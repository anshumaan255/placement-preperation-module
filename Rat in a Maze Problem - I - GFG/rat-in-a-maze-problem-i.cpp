//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,int n,string a,vector<string> &ans,vector<vector<int>> &m,vector<vector<int>> &vis){
        if(i==n-1 && j==n-1){
            ans.push_back(a);
            return ;
        }
        
        if(i+1<n && vis[i+1][j] == 0 && m[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,n,a+'D',ans,m,vis);
            vis[i][j]=0;
        }
        
        if(j-1>=0 && vis[i][j-1] == 0 && m[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,n,a+'L',ans,m,vis);
            vis[i][j]=0;
        }
        
        if(j+1<n && vis[i][j+1] == 0 && m[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,n,a+'R',ans,m,vis);
            vis[i][j]=0;
        }
        
        if(i-1>=0 && vis[i-1][j] == 0 && m[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,n,a+'U',ans,m,vis);
            vis[i][j]=0;
        }
        
        return;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1)solve(0,0,n,"",ans,m,vis);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends