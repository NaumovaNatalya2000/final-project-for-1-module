#include<iostream>
#include<string>
#include "User.h"
#include "Functions.h"
unsigned counter = 0;

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	//задаем размер массива пользователей и создаем массив
	const unsigned usersCount = 5;
	auto arrUser{ std::make_unique<User[]>(usersCount) };

	char basic{}; //переменная для перехода по базовому меню
	char choiceReg{}; //переменная для подменю регистрации
	char choiceMessage{}; //переменная для подменю отправки сообщений

	//основное меню, которое видно при входе в программу
	while (basic != 'q' && basic != 'Q') {
		cout << "------------Основное меню программы Чатик------------\n"
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
				//проверка не заполнен ли лимит пользователей
				if (counter + 1 == usersCount) {
					cout << "Достигнут лимит пользователей. Больше зарегистровать нельзя!" << endl;
					break;
				}
				NewUser(arrUser.get(), counter, usersCount);
				counter++;
				cout << "Вы хотите создать еще одного пользователя?(Введите y)\n"
					<< "Если Вы хотите вернуться в главное меню, введите любой другой символ\n" << endl;
				cin >> choiceReg;
			} while (choiceReg == 'y' || choiceReg == 'Y');
		}
		//подменю отправки сообщений
		else if (basic == '2') {
			do {
				string login;
				string password;

				cout << "------------Отправка сообщений------------\n"
					<< "Выберите пункт меню:\n"
					<< "1 - Вывести список доступных логинов"
					<< "2 - Вход по логину\n"
					<< "q - для возврата на основное меню" << endl;
				cin >> choiceMessage;

				if (choiceMessage == '1') {
					//функция вывода всех пользователей
					cout << "Список пользователей:" << endl;
					for (int i{}; i < usersCount; i++) {
						if (arrUser[i].getIsValid() == true) {
							cout << arrUser[i].getLogin() << endl;
						}
					}
				}
				if (choiceMessage == '2') {
					cout << "Вход в систему\n"
						<< "Введите логин" << endl;
					cin >> login;
				}
			} while (choiceMessage != 'q' && choiceMessage != 'Q');
		}
	}
}