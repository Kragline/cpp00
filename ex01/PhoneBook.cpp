#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_count = 0;
}

PhoneBook::~PhoneBook()
{
}

bool	PhoneBook::_isAllNum(const std::string &str)
{
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

bool	PhoneBook::_isAllSpace(const std::string &str)
{
	for (int i = 0; str[i]; i++)
		if (!isspace(str[i]))
			return (false);
	return (true);
}

bool	PhoneBook::_isValid(const std::string &str, bool checkNums)
{
	if (str.empty())
		return (false);
	if (_isAllSpace(str))
		return (false);
	if (checkNums && !_isAllNum(str))
		return (false);
	return (true);
}

std::string	PhoneBook::_setField(const std::string &name, bool checkNums)
{
	std::string	userInput;

	while (true)
	{
		std::cout << "Enter " << name << " -> ";
		getline(std::cin, userInput);
		if (_isValid(userInput, checkNums))
			break;
		if (std::cin.eof())
			break ;
	}
	return (userInput);
}

int	PhoneBook::_indexToInt(const std::string &str)
{
	int	index;

	if (str.length() > 1 || !isdigit(str[0]))
		return (-1);
	index = str[0] - '0';
	if (index < 0 || index > _count - 1)
		return (-1);
	return (index);
}

int	PhoneBook::_askForIndex()
{
	int			index;
	std::string	userInput;

	while (true)
	{
		std::cout << "Enter index to search for a contact or type CANCEL -> ";
		getline(std::cin, userInput);
		if (userInput == "CANCEL")
			return (-1);
		index = _indexToInt(userInput);
		if (index != -1)
			break;
		else if (!userInput.empty())
			std::cout << "Invalid index" << std::endl;
		if (std::cin.eof())
			break ;
	}
	return (index);
}

void	PhoneBook::add()
{
	std::string fName = _setField("first name", false);
	if (std::cin.eof())
		return ;
	std::string sName = _setField("second name", false);
	if (std::cin.eof())
		return ;
	std::string nName = _setField("nickname", false);
	if (std::cin.eof())
		return ;
	std::string pNum = _setField("phone number (numbers only)", true);
	if (std::cin.eof())
		return ;
	std::string dSec = _setField("darkest secret", false);
	if (std::cin.eof())
		return ;
	_contacts[_count] = Contact(fName, sName, nName, pNum, dSec, _count);
	if (++_count == 8)
		_count = 0;
}

void	PhoneBook::search()
{
	int	index;

	if (_count == 0)
	{
		std::cout << "You dont have contacts yet, try to add one" << std::endl;
		return ;
	}
	std::cout << std::right;
	for (int i = 0; i < _count; i++)
		_contacts[i].printFormatted();
	index = _askForIndex();
	if (std::cin.eof() || index == -1)
		return ;
	_contacts[index].printAllInfo();
}
