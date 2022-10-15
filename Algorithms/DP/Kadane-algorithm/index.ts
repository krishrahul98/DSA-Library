const kadane = (arr: Array<number>) : number => {
    if(!arr || !arr.length) return 0
    let max = Number.MIN_SAFE_INTEGER
    let curr = 0;
    arr.forEach(num => {
        curr = Math.max(num, num + curr)
        max = Math.max(curr, max)
    })
    return max
}

const main = (): void => {
    console.log(kadane([ -2, -3, 4, -1, -2, 1, 5, -3 ]))
}

main()
