﻿#include "Functions.h"

void NewUser(User* users, unsigned& counter, const unsigned& usersCount)
{
	std::string login, password, name;
	std::cout <<"-------------Создание нового пользователя-------------\n"
		<<"Введите логин" << std::endl;
	//проверка на повторяющийся логин
	bool check = true;
	while (check) {
		std::cin >> login;
		check = false;
		for (int i{}; i < usersCount; i++) {
			if (users[i].getIsValid() && login == users[i].getLogin()) {
				std::cout << "Введен логин, который уже имеется в системе\n"
					<< "Введите логин повторно" << std::endl;
				check = true;
				break;
			}
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
	counter++;
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
		if (counter == usersCount) {
			std::cout << "Достигнут лимит пользователей. Больше зарегистрировать нельзя!" << std::endl;
			break;
		}
		NewUser(users, counter, usersCount);

		
		std::cout << "Вы хотите создать еще одного пользователя?(Введите y)\n"
			<< "-----------------------------------------------------\n"
			<< "Если Вы хотите вернуться в главное меню, введите любой другой символ" << std::endl;
		std::cin >> choiceReg;
		system("cls");
	} while (choiceReg == 'y' || choiceReg == 'Y');
}

void submenuMessage(User* users, const unsigned& usersCount, std::vector<Messages>& messages)
{
	char choiceMessage{};
	do {
		std::string login;
		std::string password;

		std::cout << "------------Отправка сообщений------------\n"
			<< "Выберите пункт меню:\n"
			<< "1 - Вывести список доступных логинов\n"
			<< "2 - Вход по логину\n"
			<< "q - для возврата на основное меню" << std::endl;
		std::cin >> choiceMessage;
		system("cls");
		if (choiceMessage == '1') {
			//функция вывода всех пользователей
			std::cout << "Список пользователей:" << std::endl;
			for (int i{}; i < usersCount; i++) {
				if (users[i].getIsValid() == true) {
					std::cout << users[i].getLogin() << std::endl;
				}
			}
		}
		if (choiceMessage == '2') {
			std::cout << "------------Вход в систему------------\n"
				<< "Введите логин:" << std::endl;
			std::cin >> login;
			//найден ли логин
			bool search = false;
			//запись найденного элемента
			unsigned i = 0;

			for (; i < usersCount; i++) {
				//проход по всем пользователям
				if (users[i].getIsValid() == true && users[i].getLogin() == login) {
					search = true;
					break;
				}
			}
			//если логин найден успешно
			if (search == true) {
				std::cout << "Пользователь с логином " << login << " найден\n"
					<< "Введите пароль:" << std::endl;
				std::cin >> password;
				//если пароль совпадает
				if (users[i].getPassword() == password) {
					system("cls");
					//здесь у меня уже есть индекс пользователя - i - передаем его в новое подменю
					submenuSending(users, usersCount, i, messages);
				}
				else {
					std::cout << "Пароль введен неверно" << std::endl;
				}
			}
			//если логин не найден
			else {
				std::cout << "Введенного логина не существует" << std::endl;
			}
		}
	} while (choiceMessage != 'q' && choiceMessage != 'Q');
}

void submenuSending(User* users, const unsigned& usersCount, unsigned& index, std::vector<Messages>& messages)
{
	char choice;
	do {
		std::cout << "Вы вошли в систему под логином: " << users[index].getLogin() << "\n"
			<< "1 - Вывести список пользователей\n"
			<< "2 - Отправка сообщений одному пользователю\n"
			<< "3 - Отправка сообщений всем пользователям\n"
			<< "4 - Вывести список сообщений для меня\n"
			<< "q - для возврата на предыдущее меню " << std::endl;
		std::cin >> choice;
		system("cls");
		if (choice == '1') {
			std::cout << "Список пользователей:" << std::endl;
			for (int i{}; i < usersCount; i++) {
				if (users[i].getIsValid() == true) {
					std::cout << users[i].getLogin() << std::endl;
				}
			}
		}
		else if (choice == '2') {
			system("cls");
			//отправитель
			std::string fromUser = users[index].getLogin();
			//получатель
			std::string toUser;
			//текст сообщения
			std::string text;

			std::cout << "---Отправка сообщения конкретному пользователю---\n"
				<< "Введите логин, кому хотите отправить сообщение" << std::endl;
			std::cin >> toUser;
			//найден ли логин
			bool search = false;
			//запись найденного элемента
			unsigned i = 0;

			for (; i < usersCount; i++) {
				//проход по всем пользователям
				if (users[i].getIsValid() == true && users[i].getLogin() == toUser) {
					search = true;
					break;
				}
			}
			if (search) {
				std::cout << "Пользователь под логином " << toUser << " найден\n"
					<< "Введите текст сообщения" << std::endl;
				//чистка буфера
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, text);
				messages.push_back(Messages(fromUser, toUser, text));
			}
			else {
				std::cout << "Логин не найден" << std::endl;
			}
		}

		else if (choice == '3') {
			system("cls");
			//отправитель
			std::string fromUser = users[index].getLogin();
			//получатель
			std::string toUser = "all";
			//текст сообщения
			std::string text;
			std::cout << "Введите текст сообщения" << std::endl;
			//чистка буфера
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, text);
			messages.push_back(Messages(fromUser, toUser, text));
		}



		else if (choice == '4') {
			std::cout << "Список сообщений:" << std::endl;
			for (int i{}; i < messages.size(); i++) {
				if (messages[i].getToUser() == users[index].getLogin() || messages[i].getToUser() == "all") {
					std::cout<<"Сообщение от "<< messages[i].getFromUser()<<":\t" << messages[i].getText() << std::endl;
				}
			}
			system("pause");
			system("cls");

		}


	} while (choice!='q' && choice!= 'Q');
}
