// Complete the countInversions function below.
function countInversions(arr, p, r) {
    if(p < r){
        let q, cl, cr;
        q = Math.floor((p+r)/2);
        cl = countInversions(arr, p, q);
        cr = countInversions(arr, q+1, r);
        return merge(arr, p, q, r)+cl+cr;
    }
    return 0;
}

function merge(arr, p, q, r){
    let auxArrLeft = arr.slice(p, q+1);
    let auxArrRigh = arr.slice(q+1, r+1);
    let z = q+1;
    auxArrLeft.push(Math.pow(10, 1000));
    auxArrRigh.push(Math.pow(10, 1000));
    let i, j, countInversions;
    i = j = countInversions = 0;
    for(let k = p; k <= r; k++){
        if(auxArrLeft[i] <= auxArrRigh[j]){
            arr[k] = auxArrLeft[i];
            i++;
        } else{
            arr[k] = auxArrRigh[j];
            j++;
            countInversions += (z-k);
            z++;  
        }
    }
    return countInversions;
}

console.log(countInversions([2, 1, 5, 1, 9], 0, 4));


