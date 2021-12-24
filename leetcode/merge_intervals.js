/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    let max = 0;
    let min = 1000;
    let answer = []
    let step = []
    
    intervals = intervals.sort(function(a,b){return a[0]-b[0]})
  
    for(let i = 0; i < intervals.length; i++) {
        if(intervals[i][0] < min) min = intervals[i][0];
        if(intervals[i][1] > max) max = intervals[i][1];
    }
    for(let i = 0; i <= max-min; i++) {
        step[i] = -1;
    }
    
    for(let i = 0; i < intervals.length; i++) {
        let stepa = i
        for(let j = intervals[i][0]-min; j <= intervals[i][1]-min; j++) {
            if(step[j] != -1) {
                stepa = step[j];
                break;
            }
        }
        for(let j = intervals[i][0]-min; j <= intervals[i][1]-min; j++) {
            step[j] = stepa
        }
     }
     for(let i = 0; i <= max-min; i++) {
        if(step[i] != -1) {
            let a = step[i];
            let begin = i+min;
            console.log()
            let end = 0;
            while(i <= max-min && step[i] == a) {
                i++;
            }
            i--
            end = i+min;
            answer.push([begin,end])
        }
     }
     return answer
};
