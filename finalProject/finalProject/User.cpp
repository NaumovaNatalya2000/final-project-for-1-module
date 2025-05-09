#include "User.h"

User::User()
{
}

User::User(const std::string& login, const std::string& password, const std::string& name) : _login(login), _password(password), _name(name)
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

void User::setIsValid(const bool& newisValid)
{
	isValid = newisValid;
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

bool User::getIsValid() const
{
	return isValid;
}
