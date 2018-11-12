#include <iostream>

void main() {
	double sale, salary;
	do {
		std::cout << "판매금액을 만원단위로 입력(-1 to end):";
		std::cin >> sale;
		if (sale == -1)
			break;
		salary = 50 + 0.12*sale;
		std::cout << "이번달 급여:" << salary << std::endl;
	} while (1);
	std::cout << "프로그램종료";

}