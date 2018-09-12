function minimumBribes(q) {
    let bribes, temp;
    bribes = 0;
    for(let i = 0; i < q.length-1; i++){
        if(q[i]-(i+1) > 2 || q[i+1]-(i+2) > 2){
            return 'Too chaotic';
        }
        if(q[i] && q[i] > q[i+1]){
            temp = q[i];
            q[i] = q[i+1];
            q[i+1] = temp;
            bribes++;
            i -= 2;
        }
    }
    return bribes;
}

var arr = [2,1,5,3,4];
console.log(minimumBribes(arr));