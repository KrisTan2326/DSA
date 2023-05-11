class Solution {
private:
    string newString(string& s) {
        string newStr ;

        for(int i = 0; i < s.length(); i++) {

            char letter = s[i];
            if((letter >= 'a' && letter <= 'z') || (letter >= '0' && letter <= '9'))
                newStr.push_back(letter);

            else if(letter >= 'A' && letter <= 'Z'){
                letter = letter - 'A' + 'a';
                newStr.push_back(letter);
            }

        }

        return newStr;
    }

public:
    bool isPalindrome(string s) {
        string newStr = newString(s);

        int len = newStr.length();
        int start = 0, end = len-1;

        while(start <= end) {
            if(newStr[start] != newStr[end]) {
                return false;
            }

            start++ ;
            end-- ;
        }

        return true;
    }
};