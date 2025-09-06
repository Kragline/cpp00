#include "Account.hpp"

//////////////////////////////////////////////////////////////////////
/*								statics								*/
//////////////////////////////////////////////////////////////////////

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
	std::time_t	now;
	std::tm		*lclTime;

	now = std::time(0);
	lclTime = std::localtime(&now);
	std::cout << "[" << std::setfill('0')
			<< std::setw(4) << 1900 + lclTime->tm_year
			<< std::setw(2) << 1 + lclTime->tm_mon
			<< std::setw(2) << lclTime->tm_mday << "_"
			<< std::setw(2) << lclTime->tm_hour
			<< std::setw(2) << lclTime->tm_min
			<< std::setw(2) << lclTime->tm_sec << "]";
}

int	Account::getNbAccounts() { return (_nbAccounts); }
int	Account::getTotalAmount() { return (_totalAmount); }
int	Account::getNbDeposits() { return (_totalNbDeposits); }
int	Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

//////////////////////////////////////////////////////////////////////
/*							other methodes							*/
//////////////////////////////////////////////////////////////////////

int	Account::checkAmount() const { return (_amount); }

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	prevAmount;

	prevAmount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << prevAmount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	status;
	int		prevAmount;
	int		newAmount;

	prevAmount = _amount;
	newAmount = prevAmount - withdrawal;
	status = (newAmount >= 0) ? true : false;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << prevAmount;
	if (status)
	{
		_amount = newAmount;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal
					<< ";amount:" << _amount
					<< ";nb_withdrawals:" << _nbWithdrawals
					<< std::endl;
	}
	else
		std::cout << ";withdrawal:refused" << std::endl;
	return (status);
}
