#include "Messages.h"

Messages::Messages(const std::string& fromUser, const std::string& toFromUser, const std::string& text) : _fromUser(fromUser), _toUser(toFromUser), _text(text)
{
}

Messages::~Messages() = default;

std::string Messages::getFromUser() const
{
	return _fromUser;
}

std::string Messages::getToUser() const
{
	return _toUser;
}

std::string Messages::getText() const
{
	return _text;
}


