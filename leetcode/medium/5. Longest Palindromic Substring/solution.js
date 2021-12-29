/**
 * @param {string} s
 * @return {string}
 */

var check_palindrom = (string,start,end) => {
    for(let i = start,j=end; i<=j; i++,j--) {
        if(string[i].charCodeAt(0) !== string[j].charCodeAt(0)) {
            return false
        }
    }
    return true;
}

var longestPalindrome = function(s) {
    let answer = ""
    let max = 0
    s = s.split("")
    for(let i = 0; i < s.length; i++) {
        for(let j = i; j < s.length; j++) {
            if(check_palindrom(s,i,j) === true) {
                if(j-i+1 > max) {
                    answer = s.slice(i,j+1).join("")
                    max = j-i+1
                } 
            }
        }
    }
    return answer
};
