function hourglassSum(arr){
	let max = 0;
	let sums = [];
	for(let i = 0; i < 4; i++){
		for(let j = 1; j < 5; j++){
			sums.push(arr[i][j-1]+arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+2][j-1]+arr[i+2][j]+arr[i+2][j+1]);
		}
	}
	console.log(sums);
	return Math.max.apply(null, sums);
}
var mat = [[-1, -1, 0, -9, -2, -2],
					[-2, -1, -6, -8, -2, -5],
					[-1, -1, -1, -2, -3, -4],					
					[-1, -9, -2, -4, -4, -5],
					[-7, -3, -3, -2, -9, -9],
					[-1, -3, -1, -2, -4, -5]];
console.log(hourglassSum(mat));