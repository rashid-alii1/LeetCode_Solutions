class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int moves=0;
        int ans=0;
        int n1=arr1.size();
        int n2=arr2.size();
        for(int i=0; i<n1;i++)
        {
            for(int j=0; j<n2;j++)
            {
                if(abs(arr1[i]-arr2[j])>d)
                {
                    moves++;
                    if(moves==n2) 
                    {
                        ans++;
                    }
                }
            }
            moves=0;
        }
        return ans;
    }
};