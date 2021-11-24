/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */

var N = (number) => {
    let numbers = ["0","1","2","3","4","5","6","7","8","9"]
    return numbers.indexOf(number)
}
var multiply = function(nums1, nums2) {
    let answer = []
    for(let i = 0; i < nums1.length+nums2.length+1; i++) {
        answer.push(0) 
    }
    let first = 0, second = 0
    for(let i = 0; i < nums1.length; i++) {
        if(nums1[i] != "0") {
            first = 1
            break
        }
    }
    for(let i = 0; i < nums2.length; i++) {
        if(nums2[i] != "0") {
            second = 2
            break
        }
    }
    if(first == 0 || second == 0) return "0"
    for(let i = nums2.length - 1,k = answer.length - 1; i >= 0; i--,k--) {
        let c = k
        for(let j = nums1.length-1; j >= 0; j--) {
            answer[c - 1] += Math.floor((N(nums2[i])*N(nums1[j])+answer[c])/10)
            answer[c] = ((N(nums2[i])*N(nums1[j])+answer[c]) % 10)
            c--
        }
        
    }
    let x = 0
    while(answer[x] == 0) x++
    return answer.slice(x,answer.length).join("")
};
