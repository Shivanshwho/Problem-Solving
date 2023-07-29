class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int arr[2]={0};
        int left=0,right=0;
        int ans=0;
        while(right<answerKey.size())
        {
            if(answerKey[right]=='T')
            {
                arr[0]++;
            }
            else{
                arr[1]++;
            }
            while(min(arr[0],arr[1])>k)
            {
                if(answerKey[left]=='T')
                {
                    arr[0]--;
                }
                else{
                    arr[1]--;
                }
                left++;
            }
            ans=max(ans,(right-left+1));
            right++;
        }
        return ans;
    }
};