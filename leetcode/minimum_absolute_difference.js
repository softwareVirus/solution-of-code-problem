/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
    let answer = []
    arr.sort(function(a,b){return a-b})
    let min = 10**7
    for(let i = 0; i < arr.length-1; i++) {
        if(Math.abs(arr[i]-arr[i+1]) < min) {
            min = Math.abs(arr[i]-arr[i+1])
            answer = []
            answer.push([arr[i],arr[i+1]]);
        } else if(min == Math.abs(arr[i]-arr[i+1])){
            answer.push([arr[i],arr[i+1]]);
        }
    }
    
    return answer
};
