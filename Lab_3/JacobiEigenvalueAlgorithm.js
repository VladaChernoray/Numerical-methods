const TransposeMatrix = (a , n , b) => {
	for(let i = 1; i <= n; i++) {
		for(let j = 1; j <= n; j++) {
			b[i][j] = a[j][i];
		}
	}
}
//Function for square matrix (of order 'n') multiplication
const MulplicativeFunction = (x, y, n, s) => {
	for (let i = 1; i <= n; i++) {
		for (let j = 1; j <= n; j++) {
			s[i][j] = 0;
			for(let k = 1; k <= n; k++) {
				s[i][j] += x[i][k] * y[k][j];
			}
		}
	}
}
//Function to construct an orthogonal symmetric matrix followed from Jacobi Method's algorithm
const OrthogonalSymmetricMatrix = (C, S, n, p, q, a) => {
	console.log(a);
	for (let i = 1; i <= n; i++) {
		for (let j = 1; j <= n; j++) {
			if(i === j) a[i][j] = 1;
			if(i !== j) a[i][j] = 0;
		}
	}
	a[p][p] = C;
	a[p][q] = -S;
	a[q][p] = S;
	a[q][q] = C;
}
const MatrixMultiplication = (matrix, y, n, r) =>	//Function to compute matrix multiplication of type (S'A S), where S' means transpose of S
{
    let x1 = []
    let r1 = []
	TransposeMatrix(matrix, n, x1);
	MulplicativeFunction(x1,y,n,r1);
	MulplicativeFunction(r1,matrix,n,r);
}
//Function to clear values of all unnecessary arrays to make computation procedure smooth
const Clear = (r, b, n, a) => {
	for(let i = 1; i <= n; i++) {
		for(let j = 1; j <= n; j++) {
			a[i][j]=r[i][j];
			r[i][j]=0;
			b[i][j]=0;
		}
	}
}
const matrix =[
    [3, 1, 0],
    [1, 3, 1],
    [0, 1, 3]
]
const iteration = 100
const n = 3
function solver(a, iteration, n) {
	let p, q, t, A, B, C, S;
	let r = [];
	let b = [];
    for (let k = 1; k <= iteration; k++) {
        let temp = 0;
        for (let i = 1; i <= n; i++) {
            for (let j = 1; j <= n; j++) {
                if (i < j) {
                    if (Math.abs(a[i][j]) > temp) {
                        temp = Math.abs(a[i][j]);
                        p = i;
                        q = j;
                    }
                }
            }
        }
        if (a[p][p] < a[q][q]) t = -1;
        else t = 1;
       // console.log(a);

        A = 2 * a[p][q] * t;
        B = Math.abs(a[p][p] - a[q][q]);
        C = Math.pow(0.5 * (1 + (B / Math.pow(A * A + B * B, 0.5))), 0.5);
        S = A / (2 * C * Math.pow(A * A + B * B, 0.5));
        OrthogonalSymmetricMatrix(C, S, n, p, q, b);
        MatrixMultiplication(b, a, n, r);
        Clear(r, b, n, a);
    }

    for(let  f = 0; f <= n; f++){
        console.log(matrix[f][f]);
    }
}
let answer = solver(matrix, iteration, n);
console.log(answer);