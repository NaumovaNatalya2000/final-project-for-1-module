#include<iostream>
#include<string>
#include <cstdlib>
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
		mainMenu(basic);
		//чистка консоли
		system("cls");

		//подменю регистрации
		if (basic == '1') {
			submenuRegistration(arrUser.get(), counter, usersCount);
		}
		//подменю отправки сообщений
		else if (basic == '2') {
			do {
				string login;
				string password;
				cout << "------------Отправка сообщений------------\n"
					<< "Выберите пункт меню:\n"
					<< "1 - Вывести список доступных логинов\n"
					<< "2 - Вход по логину\n"
					<< "q - для возврата на основное меню" << endl;
				cin >> choiceMessage;
				system("cls");
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
					cout << "------------Вход в систему------------\n"
						<< "Введите логин:" << endl;
					cin >> login;
					for (int i{}; i < usersCount; i++) {
						//проход по всем пользователям
						if (arrUser[i].getIsValid() == true) {
							//проверка на совпадение логина из списка
							if (arrUser[i].getLogin() == login) {
								cout << "Пользователь с логином " << login << " найден\n"
									<< "Введите пароль:" << endl;
								cin >> password;
								if (arrUser[i].getPassword() == password) {
									cout << "Вы успешно вошли в систему под логином " << login << endl;
								}
								else {
									cout << "Пароль введен неверно" << endl;
								}
							}
							else {
								cout << "Введенного логина не существует" << endl;
							}
						}
					}
				}
			} while (choiceMessage != 'q' && choiceMessage != 'Q');
			system("cls");
		}
	}
}