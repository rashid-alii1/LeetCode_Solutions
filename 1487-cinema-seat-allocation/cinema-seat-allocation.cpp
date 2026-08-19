class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        for(auto seat: reservedSeats)
        {
            reserved[seat[0]].insert(seat[1]);
        }
        long long ans=2LL*(n-reserved.size());
        for(auto [row,seat]: reserved)
        {
            bool left=true; // 2,3,4,5
            bool middle=true; //4,5,6,7
            bool right=true; // 6,7,8,9
            for(int s=2; s<=5;s++)
            {
                if(seat.count(s))
                    left=false; 
            }
            for(int s=4; s<=7;s++)
            {
                if(seat.count(s))
                    middle=false; 
            }
            for(int s=6; s<=9;s++)
            {
                if(seat.count(s))
                    right=false; 
            }
            if(left&&right) 
                ans+=2;
            else if(left||middle||right)
                ans+=1;    
        }
        return ans;
    }
};