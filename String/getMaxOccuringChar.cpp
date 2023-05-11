class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int countOccurence[26] = {0};
        
        for(int i = 0; i < str.length(); i++) {
            int letter = str[i];
            if(letter >= 'A' && letter <= 'Z') {
                letter = letter - 'A' + 'a';
                
            }
            
            else {
                int position = letter - 97;
                countOccurence[position]++ ;
            }
        }
        
        int max = countOccurence[0];
        for(int i = 1; i < 26; i++) {
            if(countOccurence[i] > max) 
                max = countOccurence[i];
        }
        
        for(int i = 0; i < 26; i++) {
            if(countOccurence[i] == max)
                return i+97;
        }
    }

};