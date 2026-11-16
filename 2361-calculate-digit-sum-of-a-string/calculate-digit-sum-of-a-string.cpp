// class Solution {
// public:
//     int calculate(int val)
//         {
//             int sum=0;
//             while(val>0)
//             {
//                 sum+=val%10;
//                 val/=10;
//             }
//             return sum;
//         }
//     string digitSum(string s, int k) {
//         int sizee=s.size();
//         string str="";
//         int sum=0;
//         bool status=true; 
//         while(status)
//         {
//             if(sizee<k) return s;
//             else
//             {
//                 string strr="";
//                 for(int i=0; i<k; i++)
//                 {
//                     strr+=s[i];
//                 }
//                 sum=0;
//                 int ans=calculate(stoi(strr));
//                 str+= to_string(ans);
//                 if(str.size()<k)
//                 {
//                     status=false;
//                 }
//             }
//         }
//         return str;
//     }
// };



class Solution {
public:
    int calculate(string str) {
        int sum = 0;

        for (char ch : str) {
            sum += ch - '0';
        }

        return sum;
    }

    string digitSum(string s, int k) {
        while (s.size() > k) {
            string str = "";

            for (int i = 0; i < s.size(); i += k) {
                string strr = s.substr(i, k);

                int ans = calculate(strr);

                str += to_string(ans);
            }

            s = str;
        }

        return s;
    }
};
