class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        int[] dp = new int[n + 1]; // dp[i] represents the minimum number of extra characters for the substring s[0:i]
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (String word : dictionary) {
                int len = word.length();
                if (i >= len) {
                    String sub = s.substring(i - len, i);
                    if (sub.equals(word)) {
                        dp[i] = Math.min(dp[i], dp[i - len]);
                    }
                }
            }
            dp[i] = Math.min(dp[i], dp[i - 1] + 1); // Try to split at the current character.
        }

        return dp[n];
    }
}
