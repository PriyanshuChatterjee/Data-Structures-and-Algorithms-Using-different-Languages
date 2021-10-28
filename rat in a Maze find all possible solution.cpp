/*

  Consider a rat placed at (0, 0)in a square matrix of order N * N.
  It has to reach the destination at (N - 1, N - 1). 
  Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
  Note: In a path, no cell can be visited more than one time.

*/
#include <bits/stdc++.h>
#define list vector<int>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool issafe(vector<list> &m, int i,int j,int n){
        return (i<n && j<n && i>=0 &&j>=0 && m[i][j]==1 );
    }
    bool ss(vector<list> &m,int i,int j,int n,string s,vector<string>&res){
        if(i==n-1 and j==n-1 and m[i][j]==1){
           // s+="1";
           res.push_back(s);
            return true;
        }
        if(issafe(m,i,j,n))
    
        
        {   m[i][j]=0;
            ss(m,i+1,j,n,s+'D',res);
            ss(m,i-1,j,n,s+'U',res);
            ss(m,i,j+1,n,s+'R',res); 
            ss(m,i,j-1,n,s+'L',res); 
            m[i][j]=1;
        }
        return false;
    }
    vector<string> findPath(vector<list > &m, int n) {
        // Your code goes here
        string s="";
        vector<string> v;
        ss(m,0,0,n,s,v);
        
        sort(v.begin(),v.end());
       // reverse(s.begin(),s.end());
        
       // v.push_back(s);
        return v;
    }
};

    


// { Driver Code Starts.

int main() {

        int n;
        cin >> n;
        vector<list> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    
    return 0;
}  // } Driver Code Ends
