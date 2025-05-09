#include "Functions.h"

void NewUser(User* users, unsigned counter, unsigned usersCount)
{
	std::string login, password, name;
	std::cout << "Введите логин" << std::endl;

	//проверка на повторяющийся логин
	bool check = true;
	while (check) {
		std::cin >> login;
		for (int i{}; i < usersCount; i++) {
			if (login == users[i].getLogin()) {
				std::cout << "Введен логин, который уже имеется в системе\n"
					<< "Введите логин повторно" << std::endl;
				check = true;
				break;
			}
			else check = false;
		}
	}
	users[counter].setLogin(login);
	std::cout << "Введите пароль" << std::endl;
	std::cin >> password;
	users[counter].setPassword(password);
	std::cout << "Введите имя" << std::endl;
	std::cin >> name;
	users[counter].setName(name);
	//заполняем флаг заполненности логина
	users[counter].setIsValid(true);
	std::cout << "Пользователь создан успешно.\n"
		<< "Логин: " << users[counter].getLogin() << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
}
