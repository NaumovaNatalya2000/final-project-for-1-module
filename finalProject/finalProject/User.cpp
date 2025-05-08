#include "User.h"

User::User()
{
}

User::User(std::string login, std::string password, std::string name) : _login(login), _password(password), _name(name)
{
}

User::~User() = default;

void User::setLogin(const std::string& newLogin)
{
	_login = newLogin;
}

void User::setPassword(const std::string& newPassword)
{
	_password = newPassword;
}

void User::setName(const std::string& newName)
{
	_name = newName;
}

std::string User::getLogin() const
{
	return _login;
}

std::string User::getPassword() const
{
	return _password;
}

std::string User::getName() const
{
	return _name;
}
