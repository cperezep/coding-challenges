/*
Sample Input
5 4
1 2 3 4 5

Sample Output
5 1 2 3 4
*/

// Complete the rotLeft function below.
function rotLeft(a, d) {
    let n = a.length;
    let newArr = a.slice();
    let newPos;
    for(let i = 0; i < n; i++){
        newPos = i-d < 0 ? n + (i-d) : i-d;
        a[newPos] = newArr.shift();
    }
    return a;
}

var arr = [41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51]
console.log(rotLeft(arr, 10));