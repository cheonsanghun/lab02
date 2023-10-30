#include <iostream>
#include <map>
#include <string>

struct Student {
    int midscore;
    int finalscore;
};

int main() {
    int numStudents;
    std::cout << "학생 수를 입력하세요: ";
    std::cin >> numStudents;

    std::map<int, Student> students;

    for (int i = 0; i < numStudents; i++) {
        std::string name;
        int midscore, finalscore;

        std::cout << "학생 이름을 입력하세요: ";
        std::cin >> name;
        std::cout << "중간 점수를 입력하세요: ";
        std::cin >> midscore;
        std::cout << "기말 점수를 입력하세요: ";
        std::cin >> finalscore;

        students[midscore] = {midscore, finalscore};
    }

    int searchMidscore;
    std::cout << "검색할 중간 점수를 입력하세요: ";
    std::cin >> searchMidscore;

    auto it = students.find(searchMidscore);
    if (it != students.end()) {
        std::cout << "이름: " << it->second.name << ", 중간 점수: " << it->first << ", 기말 점수: " << it->second.finalscore << std::endl;
    } else {
        std::cout << "해당 중간 점수의 학생을 찾을 수 없습니다." << std::endl;
    }

    return 0;
}

