#pragma once
#include<iostream>
#include<string>
#include <vector>
#include "Messages.h"
#include "User.h"

//создание пользователя
void NewUser(User* users, unsigned& counter, const unsigned& usersCount);

//основное меню
void mainMenu(char& basic);

//подменю регистрации
void submenuRegistration(User* users, unsigned& counter, const unsigned& usersCount);

//подменю входа пользователя в систему
void submenuMessage(User* users, const unsigned& usersCount, std::vector<Messages>& messages);

//из входа пользователя подменю в отправку сообщений
void submenuSending(User* users, const unsigned& usersCount, unsigned& index, std::vector<Messages>& messages);