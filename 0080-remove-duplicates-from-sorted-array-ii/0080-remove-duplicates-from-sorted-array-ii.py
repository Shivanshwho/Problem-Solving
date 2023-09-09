class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Check if the array is empty or has only one element.
        if not nums or len(nums) == 1:
            return len(nums)
        
        # Initialize a pointer 'k' to keep track of the position where the modified array ends.
        k = 0
        
        # Initialize a variable 'count' to keep track of the count of the current element.
        count = 1  # Since we're starting from the second element, count is set to 1.
        
        # Iterate through the input array 'nums' starting from the second element (index 1).
        for i in range(1, len(nums)):
            # If the current element is equal to the previous element, increment 'count'.
            if nums[i] == nums[i - 1]:
                count += 1
            else:
                # If the current element is different from the previous element,
                # reset 'count' to 1, indicating a new unique element.
                count = 1
            
            # Check if 'count' is less than or equal to 2.
            if count <= 2:
                # If 'count' is within the limit, update the 'k'-th position in the modified array.
                k += 1
                nums[k] = nums[i]
        
        # The final 'k' value represents the length of the modified array.
        # We return 'k + 1' to account for 0-based indexing.
        return k + 1
