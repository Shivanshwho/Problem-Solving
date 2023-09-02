class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        int[] dp = new int[n + 1]; // dp[i] represents the minimum number of extra characters for the substring s[0:i]
        Arrays.fill(dp, Integer.MAX_VALUE); // Initialize dp with maximum values to find the minimum later.
        dp[0] = 0; // There are no extra characters in an empty substring.

        for (int i = 1; i <= n; i++) { // Iterate through the string s from the beginning.
            for (String word : dictionary) { // Check each word in the dictionary.
                int len = word.length(); // Get the length of the current dictionary word.
                if (i >= len) { // Check if the current substring can accommodate the word.
                    String sub = s.substring(i - len, i); // Extract a substring of the same length as the word.
                    if (sub.equals(word)) { // If the substring matches the dictionary word:
                        dp[i] = Math.min(dp[i], dp[i - len]); // Update dp[i] with the minimum extra characters found so far.
                    }
                }
            }
            dp[i] = Math.min(dp[i], dp[i - 1] + 1); // Try to split at the current character and minimize extra characters.
        }

        return dp[n]; // The result is stored in dp[n], representing the minimum extra characters for the entire string.
    }
}
