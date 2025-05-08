#include "Functions.h"

void NewUser(User& user)
{
	std::string login, password, name;
	std::cout << "Введите логин" << std::endl;
	std::cin >> login;
	user.setLogin(login);
	std::cout << "Введите пароль" << std::endl;
	std::cin >> password;
	user.setPassword(password);
	std::cout << "Введите имя" << std::endl;
	std::cin >> name;
	user.setName(name);
}
