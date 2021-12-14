/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let j = 0;
    while(1) {
        if(strs[0].length <= j) {
            break; 
        }
        let ch = strs[0][j];
        let i,c = 0;
        for(i = 0; i < strs.length; i++) {
            if(ch != strs[i][j] || strs[i].length <= j) {
                c = 1;
                break;
            }  
        }
        if(c == 1) break;
        j++;
    }
    return strs[0].split("").slice(0,j).join("");
};
