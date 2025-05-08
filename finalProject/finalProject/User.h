#pragma once
#include<iostream>

class User
{
private:
	std::string _login;
	std::string _password;
	std::string _name;
public:
	//конструктор по умолчанию
	User(std::string login, std::string password, std::string name);
	//деструктор
	~User();
	//запрещаем конструкторы копирования и присваивания
	User(const User&) = delete;
	User& operator=(const User&) = delete;
	//сеттеры
	void setLogin(const std::string& newLogin);
	void setPassword(const std::string& newPassword);
	void setName(const std::string& newName);
	//геттеры
	std::string getLogin() const;
	std::string getPassword() const;
	std::string getName() const;
};

