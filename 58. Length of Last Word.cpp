class Solution {
public:
    int lengthOfLastWord(string s) {
       int sz = s.size();
       if(sz == 1)
       return 1;
       for(int i =sz-1;i>=0;i--){
           if(s[i] != ' ')
           {
               for(int j = i;j>=0;j--){
                   // moon--*
                   //    3
                   if(s[j] == ' ')
                       return i-j;
                   
                   if(j == 0)
                   return i-j+1;
               }
           }
       }
           return 1;
    }
};