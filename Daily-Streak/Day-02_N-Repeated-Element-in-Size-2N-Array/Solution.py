class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums)

        # Check nearby elements based on observation
        for i in range(n - 1):

            # Check adjacent element
            if nums[i] == nums[i + 1]:
                return nums[i]

            # Check two steps ahead
            if i + 2 < n and nums[i] == nums[i + 2]:
                return nums[i]

            # Check three steps ahead
            if i + 3 < n and nums[i] == nums[i + 3]:
                return nums[i]

        # As per constraints, this line will never fail
        return -1
