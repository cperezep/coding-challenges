function ransomNote(magazine, note){
	let hashObject = {};
	magazine.split(" ").forEach(word => hashObject[word] = hashObject[word] ? hashObject[word]+1 : 1);

	let arr = note.split(" ");
	for(let i = 0; i < arr.length; i++){
		if(!hashObject[arr[i]])
			return "No";
		else
			hashObject[arr[i]]--;
	}
	return "Yes";
}

console.log(ransomNote("give me one grand today night", "give one grand today"));