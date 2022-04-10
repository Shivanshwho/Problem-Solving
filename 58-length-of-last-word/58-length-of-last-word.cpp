class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_index = s.size() - 1;
        int count = 0;
        int first = 0;
        for(int i = last_index; i >= 0; i--)
        {
            if(s[i] != ' ')
            {    count ++;
            if(first == 0)
                first += 1;
            }
            else if(first == 1 && s[i] == ' ')
                return count;
        }
        return count;
    }
};