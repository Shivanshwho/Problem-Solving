class Solution {
    public int islandPerimeter(int[][] A) {
        int length = 1;
        int totalSides = 0;
        
        for (int row = 0; row < A.length; row++) {
            for (int col = 0; col < A[row].length; col++) {
                if (A[row][col] == 0) continue;
                
                int tempTotalSides = 4;  // Start with 4 sides for a land cell
                
                int leftCellValue = 0;    // Value of the left neighbor cell
                int rightCellValue = 0;   // Value of the right neighbor cell
                int topCellValue = 0;     // Value of the top neighbor cell
                int bottomCellValue = 0;  // Value of the bottom neighbor cell
                
               if (col - 1 >= 0)
    leftCellValue = A[row][col - 1] == 1 ? 1 : 0;

if (col + 1 < A[0].length)
    rightCellValue = A[row][col + 1] == 1 ? 1 : 0;

if (row + 1 < A.length)
    bottomCellValue = A[row + 1][col] == 1 ? 1 : 0;

if (row - 1 >= 0)
    topCellValue = A[row - 1][col] == 1 ? 1 : 0;
                
                // Calculate the actual number of sides by subtracting the neighboring land cells
                tempTotalSides -= (leftCellValue + rightCellValue + bottomCellValue + topCellValue);
                
                totalSides += tempTotalSides;
            }
        }
        
        return length * totalSides;
    }
}
