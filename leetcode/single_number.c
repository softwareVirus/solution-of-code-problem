// I use bubble sort. if you wanna make the complexity O(nlogn), you can use heap sort or any difference sort alghorithm, by the way.

int singleNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < numsSize-1;j++) {
            if(nums[i] < nums[j]) {
                int hold = nums[i];
                nums[i] = nums[j];
                nums[j] = hold;
            }
        }
    }
    int counter = 1;
    for(int i = 0; i < numsSize-1; i++) {
        if(nums[i] == nums[i+1]) {
            counter++;
        } else {
            if(counter == 1) return nums[i];
            counter = 1;
        }
    }
    return nums[numsSize-1];
}
