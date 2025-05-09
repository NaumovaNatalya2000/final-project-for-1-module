#pragma once
#include<iostream>
#include<string>
class Messages
{
private:
	//отправитель
	std::string _fromUser;
	//получатель
	std::string _toUser;
	//текст сообщения
	std::string _text;
public:
	//конструктор
	Messages(const std::string& fromUser, const std::string& toFromUser, const std::string& text);
	//деструктор
	~Messages();

	std::string getFromUser() const;
	std::string getToUser() const;
	std::string getText() const;
};

