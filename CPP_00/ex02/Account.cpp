#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(){
	std::time_t now = std::time(NULL);
	std::tm *lt = std::localtime(&now);

	std::cout << "["
			<< (lt->tm_year + 1900)
			<< std::setw(2) << std::setfill('0') << lt->tm_mon + 1
			<< std::setw(2) << std::setfill('0') << lt->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << lt->tm_hour
			<< std::setw(2) << std::setfill('0') << lt->tm_min
			<< std::setw(2) << std::setfill('0') << lt->tm_sec
			<< "]";
}

Account::Account(int initial_deposit){
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created"
			<< std::endl;
}


Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed"
			<< std::endl;
}

int	Account::getNbAccounts(void){
	return _nbAccounts;
}

int	Account::getTotalAmount(void){
	return _totalAmount;
}

int	Account::getNbDeposits(void){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void){
	return _totalNbWithdrawals;
}

void	Account::makeDeposit(int deposit){
	int prev_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << prev_amount
			<< ";deposit:" << deposit
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
	int prev_amount = this->_amount;
	if (withdrawal > this->_amount){
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << prev_amount
				<< ";withdrawal:refused"
				<< std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << prev_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return true;
}

int	Account::checkAmount(void)const{
	return this->_amount;
}

void	Account::displayStatus(void)const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void	Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}