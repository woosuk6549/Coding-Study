#include <iostream>

void main() {
	double sale, salary;
	do {
		std::cout << "�Ǹűݾ��� ���������� �Է�(-1 to end):";
		std::cin >> sale;
		if (sale == -1)
			break;
		salary = 50 + 0.12*sale;
		std::cout << "�̹��� �޿�:" << salary << std::endl;
	} while (1);
	std::cout << "���α׷�����";

}