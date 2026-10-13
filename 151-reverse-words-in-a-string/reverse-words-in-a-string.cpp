class Solution {
public:
    string reverseWords(string s) {
        int n =s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for( int  i =0 ; i<n ; i++){   // traverse a string 
            string word = "";

            while(i < n &&  s[i] != ' '){
                word += s[i];
                i++;
            }
            
            reverse( word.begin() , word.end());
            if( word.length() >0){
                ans += " " + word;  // for adding a extra space
            }
        }
                return ans.substr(1) ;
        
    }
};