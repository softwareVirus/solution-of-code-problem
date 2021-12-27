/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
    let answer = ""
    for(let i = 0; num != 1; i++) {
        answer += (Number(num%2)+1)%2
        num = Math.floor(num/2)
    }
    answer+=0
    answer = answer.split("").reverse().join("")
    
    return parseInt(answer,2)
};
