/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */

var distance_cal = (x,y) => {
    return Math.sqrt(x*x+y*y);
}

var kClosest = function(points, k) {
    let distance = []
    for(let i = 0; i < points.length; i++) {
        distance[i] = []
        distance[i].push(distance_cal(points[i][0],points[i][1]))
        distance[i].push(i)
    }
    distance = distance.sort(function(a,b){return a[0]-b[0]})
    let answer = []
    for(let i = 0; i < k; i++) {
        answer.push(points[distance[i][1]])
    }
    return answer
};
