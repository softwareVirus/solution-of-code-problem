/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    nums = nums.sort(function(a,b){return a-b})
    let h = 0
    for(let i = 0; i < nums.length; i++) {
        if(h != nums[i]) break;
        h++
    }
    return h
};
