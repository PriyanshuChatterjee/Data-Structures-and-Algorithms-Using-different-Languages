/*Given an expression string x. 
Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” 
and 'false' for exp = “[(])”.*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
    stack<char> st;
    int i=0;
    while(i<s.length()){
        if(s[i]=='(' ||s[i]=='[' ||s[i]=='{')
            st.push(s[i]);
        else if(s[i]==')' ||s[i]=='}' ||s[i]==']'){
            if(s[i]==')' ){
                while(!st.empty() && st.top()!='('){
                    if(st.top()!='(')
                        return false;
                    st.pop();
                }
                    
                if(st.empty())
                    return false;
                st.pop();
            }
            if(s[i]=='}' ){
                while(!st.empty() && st.top()!='{'){
                    if(st.top()!='{')
                        return false;                    
                    st.pop();
                }
                if(st.empty())
                    return false;
                st.pop();               
            }
            if(s[i]==']' ){
                while(!st.empty() && st.top()!='['){
                    if(st.top()!='[')
                        return false;                    
                    st.pop();
                }
                if(st.empty())
                    return false;
                st.pop();                
            }            
        }
        i++;
        // Your code here
    }
    if(st.empty())
        return true;
    return false;
}
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;

   cin>>a;
   Solution obj;
   if(obj.ispar(a))
        cout<<"balanced"<<endl;
   else
       cout<<"not balanced"<<endl;

}  // } Driver Code Ends
