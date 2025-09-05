#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName,
				std::string phoneNumber, std::string darkestSecret, int index)
{
	_index = index;
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

Contact::~Contact()
{
}

std::string	Contact::_formatString(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return (str);
}

void	Contact::printFormatted()
{
	std::cout << "|" << _index << "|";
	std::cout << std::setw(10) << _formatString(_firstName) << "|";
	std::cout << std::setw(10) << _formatString(_lastName) << "|" ;
	std::cout << std::setw(10) << _formatString(_nickname) << "|" << std::endl ;
}

void	Contact::printAllInfo()
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
