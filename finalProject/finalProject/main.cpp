#include<iostream>
#include<string>
#include "User.h"
#include "Functions.h"
unsigned counter = 0;

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	//задаем размер массива пользователей и создаем массив
	const unsigned usersCount = 20;
	auto arrUser{ std::make_unique<User[]>(usersCount) };

	//основное меню, которое видно при входе в программу
	char basic{}; //переменная для перехода по базовому меню
	char choice{}; //переменная для подменю
	while (basic != 'q') {
		cout << "Основное меню программы Чатик\n"
			<< "-------------------------------\n"
			<< "Выберите пункт меню:\n"
			<< "1 - Регистрация пользователя в системе\n"
			<< "2 - Вход в чат(если уже прошли регистрацию)\n"
			<< "-------------------------------\n"
			<< "Введите q для выхода из программы(все данные будут удалены!)" << endl;
		cin >> basic;

		//подменю регистрации
		if (basic == '1') {
			do {
				NewUser(arrUser.get(), counter, usersCount);
				counter++;
				cout << "Вы хотите создать еще одного пользователя?(Введите y)\n"
					<< "Если Вы хотите вернуться в главное меню, введите любой другой символ\n" << endl;
				cin >> choice;
			} while (choice == 'y' || choice == 'Y');
		}
	}
}