class Solution {
public:
    int maxDepth(string s) {
        int n=0, depth=0;
        for(char ch: s)
        {
            if(ch=='(')
            {
                n++;
                depth=max(depth,n);
            }
            else if(ch==')')
            {
                n--;
            }
        }
        return depth;
    }
};