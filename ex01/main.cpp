#include "PhoneBook.hpp"

static void	print_usage()
{
	std::cout << "You have 3 commands avilable" << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: exits the program" << std::endl << std::endl;
}

int	main()
{
	PhoneBook	pBook;
	std::string	userInput;

	std::cout << "Welcome to the phonebook" << std::endl << std::endl;
	print_usage();
	while (true)
	{
		std::cout << "Enter command -> ";
		getline(std::cin, userInput);
		if (userInput == "ADD")
			pBook.add();
		else if (userInput == "SEARCH")
			pBook.search();
		else if (userInput == "EXIT")
			break ;
		else if (!userInput.empty())
			std::cout << "Wrong command: Commands avilable: ADD SEARCH EXIT" << std::endl;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
	}
	std::cout << std:: endl << "Phonebook was closed" << std::endl;
	return (0);
}
