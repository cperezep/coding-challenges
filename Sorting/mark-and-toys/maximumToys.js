function maximumToys(prices, k){
	let count = 0
	mergeSort(prices, 0, prices.length-1);
	while(k >= 0){
		k -= prices[count]
		count++;
	}
	return count-1;
}

function mergeSort(arr, p , r){
	if(p < r){
		let q = Math.floor((p+r)/2);
		mergeSort(arr, p, q);
		mergeSort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

function merge(arr, p, q, r){
    let auxArrLeft = arr.slice(p, q+1);
    let auxArrRigh = arr.slice(q+1, r+1);
    auxArrLeft.push(Math.pow(10, 1000));
    auxArrRigh.push(Math.pow(10, 1000));
    let i, j;
    i = j = 0;
    for(let k = p; k <= r; k++){
        if(auxArrLeft[i] <= auxArrRigh[j]){
            arr[k] = auxArrLeft[i];
            i++;
        } else{
            arr[k] = auxArrRigh[j];
            j++;
        }
    }
}

console.log(maximumToys([1,12,5,111,200,1000,10], 50));