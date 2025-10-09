#include "../Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void){

}

int	Account::getNbAccounts(){
	return _nbAccounts;
}

int	Account::getTotalAmount(){
	return _totalAmount;
}

int	Account::getNbDeposits(){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(){
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
			<< ";nb_deposits:" << this->_nbDeposits;
}

bool	Account::makeWithdrawal(int withdrawal){
	int prev_amount = this->_amount;
	if (withdrawal > this->_amount){
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << prev_amount
				<< ";withdrawal:refused";
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
		<< ";nb_withdrawals:" << this->_nbWithdrawals;
}

int	Account::checkAmount()const{
	return this->_amount;
}

void	Account::displayStatus()const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << this->_totalAmount
			<< ";closed";
}
// [19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
void	Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< "amount:" << 
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals;
}