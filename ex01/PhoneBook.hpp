#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
	int			_count;
	Contact		_contacts[8];
public:
	void		add();
	void		search();
	PhoneBook();
	~PhoneBook();
private:
	int			_indexToInt(const std::string &str);
	int			_askForIndex();
	std::string	_setField(const std::string &name, bool checkNums);
	bool		_isAllNum(const std::string &str);
	bool		_isAllSpace(const std::string &str);
	bool		_isValid(const std::string &str, bool checkNums);
};

#endif