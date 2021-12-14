/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let answer = []
    answer[0] = []
    let j = 0
    for(let i = 0; i < s.length; i++) {
        if(s[i] == " ") {
            if(answer[answer.length-1].length != 0) {
                j++   
                answer[j] = []
            }
            while(s[i] == " " && i < s.length) i++
            if(i < s.length) answer[j].push(s[i])
        } else {
            answer[j].push(s[i])
        }
    }
    if(answer[j].length == 0) return answer[j-1].length
    else return answer[j].length
};
