function JacobiMethod(matrix, b, eps){
    let n = matrix.length;
    let tmp_arr = new Array(n);
    let x = new Array(n);
    for(let i = 0; i < n; i++){
        x[i] = 0
    }
    let exp = 0
    do {
        for(let i = 0; i < n; i++){
            tmp_arr[i] = 0
            for (let j = 0; j < n; j++){
                if(i !== j){
                    tmp_arr[i] = tmp_arr[i] + (matrix[i][j] * x[j])
                }
            }
            tmp_arr[i] = (b[i] - tmp_arr[i]) / matrix[i][i]
        }
        exp = 0
        for(let i = 0; i < n; i++){
            if(Math.abs(x[i] - tmp_arr[i]) > exp){
                exp = Math.abs(x[i] - tmp_arr[i])
            }
            x[i] = tmp_arr[i]
        }
    } while(exp > eps)
    return x
}

function InvertibleMatrix(matrix){
    let det = Determinant(matrix);
    if (det === 0) return false;
    matrix = AdjugateMatrix(matrix);
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix.length; j++) matrix[i][j] /= det;
    }
    return matrix;
}
function AdjugateMatrix(matrix)
{
    let adjA = [];
    for (let i = 0; i < matrix.length; i++) {
        adjA[ i ] = [];
        for (let j = 0; j < matrix.length; j++) {
            let B = [];
            let sign = ((i + j) % 2 === 0) ? 1 : -1;
            for (let m = 0; m < j; m++) {
                B[m] = [];
                for (let n = 0; n < i; n++)   B[m][n] = matrix[m][n];
                for (let n = i+1; n < matrix.length; n++) B[m][n-1] = matrix[m][n];
            }
            for (let m = j + 1; m < matrix.length; m++) {
                B[m-1] = [];
                for (let n = 0; n < i; n++)   B[m-1][n] = matrix[m][n];
                for (let n = i + 1; n < matrix.length; n++) B[m-1][n-1] = matrix[m][n];
            }
            adjA[i ][j] = sign*Determinant(B);
        }
    }
    return adjA;
}
function Determinant(matrix) {
    if (matrix.length > 2) {
        let result = 0;
        for (let i = 0; i < matrix.length; i++) {
            let minor = Minor(matrix, 0, i);
            result = result + matrix[0][i] * Math.pow((-1),i) * Determinant(minor);
        }
        return result;
    }
    else if (matrix.length === 2) {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }

}
function Minor(matrix, i, j) {
    let temp = [];
    for (let i = 0; i < matrix.length - 1; i++) {
        temp[i] = new Array(matrix.length - 1);
    }
    let x = 0, y = 0;
    for (let k = 0; k < matrix.length; k++, x++) {
        if (k !== i) {
            y = 0;
            for (let t = 0; t < matrix.length; t++) {
                if (t !== j) {
                    temp[x][y] = matrix[k][t];
                    y++;
                }
            }
        }
        else {
            x--;
        }
    }
    return temp;
}
const matrix = [
    [3, 2, 0, 0, 0, 0, 0, 0, 0, 0],
    [1, 3, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 3, 2, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 3, 2, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 3, 2, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 3, 2, 0, 0, 0],
    [0, 0, 0, 0, 0, 1, 3, 2, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 3, 2, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 3, 2],
    [0, 0, 0, 0, 0, 0, 0, 0, 1, 3],
];

const kek =[
    [3, 1, 0],
    [1, 3, 1],
    [0, 1, 3]
]
const kek_v = [1, 2 ,3]
const eps = 0.0001;
const b = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

/*const answer = InvertibleMatrix(kek);
console.log("Обратная матрица: " , answer);*/
/*console.log("Детерминант: ", answer);
const answer = Determinant(kek);*/
const answer =  JacobiMethod(kek, kek_v, eps)
console.log("Метод Якоби: ", answer)
