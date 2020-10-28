function longestCommonSubsequence(string1, string2) {

    if ( string1.length === 0 | string2.length == 0 ) {
        return {string: '', length: 0};
    }
    
    let substringArray = Array(string1.length + 1)
        .fill(0)
        .map(() => Array(string2.length + 1).fill(0));

    //table filling method
    for (let i= 1; i<=string1.length ; i++)
    {
        for (let j=1 ; j<=string2.length; j++)
        {
            if (string1[i-1] === string2[j-1]){
                substringArray[i][j] = 1 + substringArray[i-1][j-1];
            } else {
                substringArray[i][j] = Math.max(substringArray[i-1][j], substringArray[i][j-1]);
            }
        }
    }
    let index = substringArray[string1.length][string2.length];
    let substring = Array(index+1).fill('')
    
    let i = string1.length;
    let j = string2.length;
    while ( i > 0 && j > 0 ) {
        if (string1[i-1] == string2[j-1]) {
            substring[index-1] = string1[i-1];
            i--;
            j--;
            index--;
        } else if(substringArray[i-1][j] > substringArray[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    string = substring.join('');
    return {string: string, length: string.length}
}

function main(string1, string2) {
    const answer = longestCommonSubsequence(string1, string2);
    console.log(`The longest substring is length ${answer.length} and the string is ${answer.string}`)
}

main('abc', 'bce')