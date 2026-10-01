class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for (char c : s) 
        {
            // If opening bracket push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
        // If closing bracket check for match
            else if (c == ')' || c == '}' || c == ']') 
            {
                // Stack empty means no matching opener
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

            // Check if brackets match
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        return st.empty();    
    }    

};