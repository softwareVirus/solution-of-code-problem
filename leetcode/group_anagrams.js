/**
 * @param {string[]} strs
 * @return {string[][]}
 */

O(nlogn)
var groupAnagrams = function(strs) {
    let keeper = []
    for(let i = 0; i < strs.length; i++) {
        keeper[i] = [];
        keeper[i][0] = strs[i].split("").sort().join("");
        keeper[i][1] = i;
    }
    keeper = keeper.sort();
    let answer = []
    let an = keeper[0]
    answer[0] = []
    let j = 0
    for(let i = 0; i < keeper.length; i++) {
        if(keeper[i][0] == an[0]) {
            answer[j].push(strs[keeper[i][1]])
        } else {
            an = keeper[i] 
            answer[j+1] = []
            answer[j+1].push(strs[keeper[i][1]])
            j++
        }
    }
    return answer
};
