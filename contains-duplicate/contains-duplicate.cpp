class Solution {
public:
    
    vector<int>& mergeSort(vector<int>& arr) {
        if(arr.size() > 1) {
            int m = arr.size() / 2; // m for midpoint 
            vector<int> L; 
            vector<int> R; 
            for (int i = 0; i < m; i++) {
                L.push_back(arr[i]);
            }
            for (int j = m; j < arr.size(); j++) {
                R.push_back(arr[j]); 
            }
            L = mergeSort(L);
            R = mergeSort(R);
            
            int i, j, k; 
            i = j = k = 0; 
            
            while ((i < L.size()) && (j < R.size())) {
                if (L[i] < R[j]){
                    arr[k] = L[i]; 
                    i++;
                    k++; 
                }
                else {
                    arr[k] = R[j];
                    j++; 
                    k++; 
                }
            }
            while (i < L.size()) {
                arr[k] = L[i]; 
                i++;
                k++; 
            }
            while (j < R.size()) {
                arr[k] = R[j]; 
                j++;
                k++; 
            }
            
        }
        return arr;   
    }
    
    bool containsDuplicate(vector<int>& nums) { 
        vector<int> sorted_nums = mergeSort(nums); 
        if (sorted_nums.size() == 1) return false; 
        int item_0 = sorted_nums[0];
        int item_1 = sorted_nums[1]; 
        for (int i = 1; i < sorted_nums.size(); i++) {
            item_0 = sorted_nums[i - 1]; 
            item_1 = sorted_nums[i]; 
            if (item_0 == item_1) return true; 
               
        }
        return false; 
    }
    
//     bool containsDuplicate(vector<int>& nums) {
//         int array_size = sizeof(nums) / sizeof(nums[0]); // can just say nums.size() 
//         for (int i = 0; i < array_size - 1; i++) {
//             for (int j = i + 1; j < array_size; j++) { 
//                 if (nums[i] == nums[j]) {
//                     return true; 
//                 }
//             }
//         }
//     return false; 
        
//     }
};