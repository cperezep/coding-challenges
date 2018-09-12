function arrayManipulation1(n, queries){
	let arr = new Array(n).fill(0);
	let partArr;
	queries.forEach(querie => {
		partArr = arr.slice(querie[0]-1, querie[1]).map(x => x+querie[2]);
		partArr.unshift.apply(partArr, [querie[0]-1, partArr.length]);
		arr.splice.apply(arr, partArr);
	});
	return Math.max.apply(null, arr);
}

function arrayManipulation2(n, queries){
	let arr = new Array(n).fill(0);
	queries.forEach(querie => {
		for(let i = querie[0]-1; i <= querie[1]-1; i++){
			arr[i] += querie[2];
		}
	});
	return Math.max.apply(null, arr);
}

// Complete the arrayManipulation function below. *
function arrayManipulation(n, queries) {
    let arr = new Array(n+1).fill(0);
    let x, max;
    x = max = 0;
    queries.forEach(querie => {
        arr[querie[0]] += querie[2];
        if(querie[1]+1 <= n){
            arr[querie[1]+1] -= querie[2];
        }
    });
    for(let i = 1; i <= n; i++){
        x += arr[i];
        if(max < x){
            max = x;
        }
    }
    return max;
}

var queries = [ [ 1, 2, 100 ], [ 2, 5, 100 ], [ 3, 4, 100 ] ];
console.log(arrayManipulation(5, queries));