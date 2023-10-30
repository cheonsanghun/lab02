use std::collections::BTreeMap;
use std::io;


#[allow(dead_code)]
struct Student {
    name: String,
    midscore: i32,
    finalscore: i32,
}

fn main() {
    let mut students = BTreeMap::new();

    let mut num_students = String::new();
    println!("학생 수를 입력하세요: ");
    io::stdin().read_line(&mut num_students).expect("입력 에러");
    let num_students: i32 = num_students.trim().parse().expect("정수를 입력하세요.");

    for _ in 0..num_students {
        let mut name = String::new();
        let mut midscore = String::new();
        let mut finalscore = String::new();

        println!("학생 이름을 입력하세요: ");
        io::stdin().read_line(&mut name).expect("입력 에러");
        let name = name.trim().to_string();

        println!("중간 점수를 입력하세요: ");
        io::stdin().read_line(&mut midscore).expect("입력 에러");
        let midscore: i32 = midscore.trim().parse().expect("정수를 입력하세요");

        println!("기말 점수를 입력하세요: ");
        io::stdin().read_line(&mut finalscore).expect("입력 에러");
        let finalscore: i32 = finalscore.trim().parse().expect("정수를 입력하세요");

        students.insert(midscore, Student { name, midscore, finalscore });
    }

    let mut search_midscore = String::new();
    println!("검색할 중간 점수를 입력하세요: ");
    io::stdin().read_line(&mut search_midscore).expect("입력 에러");
    let search_midscore: i32 = search_midscore.trim().parse().expect("정수를 입력하세요");

    match students.get(&search_midscore) {
        Some(student) => {
            println!("이름: {}, 중간 점수: {}, 기말 점수: {}", student.name, search_midscore, student.finalscore);
        }
        None => {
            println!("해당 중간 점수의 학생을 찾을 수 없습니다.");
        }
    }
}

