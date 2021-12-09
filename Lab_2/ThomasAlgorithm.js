const ThomasAlgorithm = (a, b, c, d) => {
    let x = [];
    let q;
    let n = b.length - 1;
    for (let i = 1; i <= n; i++) {
        q = a[i] / b[i - 1];
        b[i] = b[i] - c[i - 1] * q;
        d[i] = d[i] - d[i - 1] * q;
        console.log("q = ", q, "b[i] = ", b[i], "d[i] = ", d[i])
    }
    q = d[n] / b[n];
    x[n] = q;
    for (let i = n - 1; i >= 0; i--) {
        q = (d[i] - c[i] * q) / b[i];
        x[i] = q;
    }
    return x;
}

const getTemp = (matrix, n) => {
    let a = [];
    let b = [];
    let c = [];

    for (let i = 0; i <= n - 1; i++){
        for (let j = 0; j <= n - 1; j++){
            if (i === j){
                b[i] = matrix[i][j];
                //console.log(b[i])
            }
            if (i === j - 1){
                a[i] = matrix[i][j];
                a[n-1] = 0;
            }
            if (i === j + 1){
                c[i] = matrix[i][j];
                //console.log(c[i])
            }
        }
        c = c.filter(Number)
        c.unshift(0);
    }
    return {
        c: c,
        a: a,
        b: b,
    }
}

const coefficientMatrix = [
    [2, 3, 0, 0, 0],
    [1, 3, 9, 0, 0],
    [0, 2, 5, 2, 8],
    [0, 0, 4, 3, 4],
    [0, 0, 0, 8, 9]
];

const kek_1 = [
    [3, 2, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 3, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 3, 2, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 3, 2, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 3, 2, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 3, 2, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 3, 2, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 3, 2, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 3, 2],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 3]
]
const kek_2 = [
    [3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 3, 2, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 3, 2, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 3, 2, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 3, 2, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 3, 2, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 2, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 2],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3]
]
const d = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
const n = 12
const kek_3 =[
    [3, 1, 0],
    [1, 3, 1],
    [0, 1, 3]
]
const kek_v = [1, 2 ,3];

function solver(kek_3, kek_v, n){
    const result = getTemp(kek_3, n);
    console.log(result);
    return ThomasAlgorithm(result.a, result.b, result.c, kek_v, n)
}
const answer =  solver(kek_2, d, n);
console.log(answer);