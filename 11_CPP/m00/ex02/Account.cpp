#include "Account.hpp"
#include <iostream>
//#include <ctime>

# define	BLUE		"\033[0;34m"
# define	OFF			"\033[0m"


int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = Account::_nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	std::cout << "index:" << BLUE << _accountIndex << OFF << ";"
			<< "amount:" << BLUE << _amount << OFF << ";"
			<< "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << OFF << ";"
		<< "amount:" << BLUE << _amount << OFF << ";"
		<< "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << BLUE << _nbAccounts << OFF << ";"
		<< "total:" << BLUE << _totalAmount << OFF << ";"
		<< "deposits:" << BLUE << _totalNbDeposits << OFF << ";"
		<< "withdrawals:" << BLUE << _totalNbWithdrawals << OFF << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits += 1;
	_amount += deposit;
	_totalNbDeposits += 1;
	_totalAmount += deposit;

	std::cout << "index:" << BLUE << _accountIndex << OFF<< ";"
		<< "p_amount:" << BLUE << _amount - deposit << OFF << ";"
		<< "deposit:" << BLUE << deposit << OFF << ";"
		<< "amount:" << BLUE << _amount << OFF << ";"
		<< "nb_deposits:" << BLUE << _nbDeposits << OFF << std::endl;

}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << OFF << ";"
		<< "p_amount:" << BLUE << _amount << OFF << ";";
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_totalNbWithdrawals += 1;
		_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		std::cout << "withdrawal:" << BLUE << withdrawal << OFF << ";"
			<< "amount:" << BLUE << _amount << OFF << ";"
			<< "nb_withdrawals:" << BLUE << _nbWithdrawals << OFF << ";" << std::endl;
	}
	else
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return false;
	}

	return true;
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << BLUE << _accountIndex << OFF << ";"
			  << "amount:" << BLUE << _amount << OFF << ";"
			  << "deposits:" << BLUE << _nbDeposits << OFF << ";"
			  << "withdrawals:" << BLUE << _nbWithdrawals << OFF << std::endl;
}

void Account::_displayTimestamp()
{
	std::cout << "[19920104_091532]";
}

