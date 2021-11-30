class Solution(object):
    
    def mergeSort(self, arr): # , l, r):
        if len(arr) > 1: 
            m = len(arr) // 2 
            L = arr[:m] 
            R = arr[m:] 
            self.mergeSort(L) #, 0, m)
            self.mergeSort(R) # , 0, len(R)) 
            
            i = j = k = 0 
            
            while i < len(L) and j < len(R):
                if L[i] < R[j]:
                    arr[k] = L[i] 
                    i += 1 
                    k += 1 
                else: 
                    arr[k] = R[j] 
                    j += 1 
                    k += 1 
            while i < len(L): 
                arr[k] = L[i] 
                i += 1 
                k += 1
            while j < len(R):
                arr[k] = R[j] 
                j += 1 
                k += 1    
        return arr 
        
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        sorted_nums = self.mergeSort(nums) 
        print ("sorted array:")
        print (sorted_nums)
        
        if len(nums) == 1:
            return False 
        
        item_0 = sorted_nums[0] 
        item_1 = sorted_nums[1] 
        
        for ix, item_1 in enumerate(sorted_nums[1:]): 
            item_0 = sorted_nums[ix] 
            if item_1 == item_0:
                return True 
        return False 
        
        
        # for i in range(len(nums) - 1):
        #     for j in range(i + 1, len(nums)): 
        #         if nums[i] == nums[j]:
        #             return True 
        # return False 
        