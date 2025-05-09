#include<iostream>
#include<string>
#include <cstdlib>
#include "User.h"
#include "Functions.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	unsigned counter = 0;
	//задаем размер массива пользователей и создаем массив
	const unsigned usersCount = 5;
	auto arrUser{ std::make_unique<User[]>(usersCount) };

	char basic{}; //переменная для перехода по базовому меню

	//основное меню, которое видно при входе в программу
	while (basic != 'q' && basic != 'Q') {
		mainMenu(basic);
		//чистка консоли
		system("cls");

		//подменю регистрации
		if (basic == '1') {
			submenuRegistration(arrUser.get(), counter, usersCount);
		}
		//подменю отправки сообщений
		else if (basic == '2') {
			submenuMessage(arrUser.get(), usersCount);
			system("cls");
		}
	}
}