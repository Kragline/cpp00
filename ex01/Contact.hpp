#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
public:
	Contact();
	Contact(std::string firstName, std::string lastName, std::string nickName,
			std::string phoneNumber, std::string darkestSecret, int index);
	~Contact();
	void	printFormatted();
	void	printAllInfo();
private:
	std::string	_formatString(const std::string &str);
};

#endif