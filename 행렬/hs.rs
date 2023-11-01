use std::io;

fn main() {
    let mut input = String::new();
    println!("첫 번째 행렬의 행 수: ");
    io::stdin().read_line(&mut input).expect("입력 에러");
    let rows1: usize = input.trim().parse().expect("잘못된 입력");

    input.clear();
    println!("첫 번째 행렬의 열 수: ");
    io::stdin().read_line(&mut input).expect("입력 에러");
    let cols1: usize = input.trim().parse().expect("잘못된 입력");

    let mut matrix1: Vec<Vec<i32>> = vec![vec![0; cols1]; rows1];
    println!("첫 번째 행렬의 원소를 입력하세요:");

    for i in 0..rows1 {
        for j in 0..cols1 {
            loop {
                input.clear();
                io::stdin().read_line(&mut input).expect("입력 에러");
                if let Ok(element) = input.trim().parse() {
                    matrix1[i][j] = element;
                    break;
                } else {
                    println!("잘못된 입력입니다. 다시 시도하세요.");
                }
            }
        }
    }

    input.clear();
    println!("두 번째 행렬의 행 수: ");
    io::stdin().read_line(&mut input).expect("입력 에러");
    let rows2: usize = input.trim().parse().expect("잘못된 입력");

    input.clear();
    println!("두 번째 행렬의 열 수: ");
    io::stdin().read_line(&mut input).expect("입력 에러");
    let cols2: usize = input.trim().parse().expect("잘못된 입력");

    let mut matrix2: Vec<Vec<i32>> = vec![vec![0; cols2]; rows2];
    println!("두 번째 행렬의 원소를 입력하세요:");

    for i in 0..rows2 {
        for j in 0..cols2 {
            loop {
                input.clear();
                io::stdin().read_line(&mut input).expect("입력 에러");
                if let Ok(element) = input.trim().parse() {
                    matrix2[i][j] = element;
                    break;
                } else {
                    println!("잘못된 입력입니다. 다시 시도하세요.");
                }
            }
        }
    }

    let mut result: Vec<Vec<i32>> = vec![vec![0; cols1]; rows1];

    for i in 0..rows1 {
        for j in 0..cols1 {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    println!("두 행렬을 더한 결과:");
    for i in 0..rows1 {
        for j in 0..cols1 {
            print!("{} ", result[i][j]);
        }
        println!();
    }
}
