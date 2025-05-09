#include "Functions.h"

void NewUser(User* users, unsigned& counter, const unsigned& usersCount)
{
	std::string login, password, name;
	std::cout <<"-------------Создание нового пользователя-------------\n"
		<<"Введите логин" << std::endl;
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

void mainMenu(char& basic)
{
	std::cout << "------------Основное меню программы Чатик------------\n"
		<< "-----------------------------------------------------\n"
		<< "Выберите пункт меню:\n"
		<< "1 - Регистрация пользователя в системе\n"
		<< "2 - Вход в чат(если уже прошли регистрацию)\n"
		<< "-----------------------------------------------------\n"
		<< "Введите q для выхода из программы(все данные будут удалены!)" << std::endl;
	std::cin >> basic;
}

void submenuRegistration(User* users, unsigned& counter, const unsigned& usersCount)
{
	char choiceReg{};
	do {
		//проверка не заполнен ли лимит пользователей
		if (counter + 1 == usersCount) {
			std::cout << "Достигнут лимит пользователей. Больше зарегистровать нельзя!" << std::endl;
			break;
		}
		NewUser(users, counter, usersCount);

		counter++;
		std::cout << "Вы хотите создать еще одного пользователя?(Введите y)\n"
			<< "-----------------------------------------------------\n"
			<< "Если Вы хотите вернуться в главное меню, введите любой другой символ" << std::endl;
		std::cin >> choiceReg;
		system("cls");
	} while (choiceReg == 'y' || choiceReg == 'Y');
}
