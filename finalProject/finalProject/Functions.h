#pragma once
#include<iostream>
#include<string>
#include "User.h"

//создание пользователя
void NewUser(User* users, unsigned& counter, const unsigned& usersCount);

//основное меню
void mainMenu(char& basic);

//подменю регистрации
void submenuRegistration(User* users, unsigned& counter, const unsigned& usersCount);

//подменю отправки сообщений
void submenuMessage(User* users, const unsigned& usersCount);