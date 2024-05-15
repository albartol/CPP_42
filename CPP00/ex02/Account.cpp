/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:59:25 by albartol          #+#    #+#             */
/*   Updated: 2024/05/15 15:41:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";created\n";
	_nbAccounts++;
	_totalAmount = _totalAmount + _amount;
}

Account::Account(void) : _accountIndex(_nbAccounts), _amount(0),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";created\n";
	_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";closed\n";
	_nbAccounts--;
	_totalAmount = _totalAmount - _amount;
}

void	Account::_displayTimestamp(void)
{
	time_t	timer;
	struct tm	*time_info;

	time(&timer);
	time_info = localtime(&timer);
	std::cout << "[" << (time_info->tm_year + 1900)
		<< std::setfill ('0') << std::setw (2) << time_info->tm_mon
		<< std::setfill ('0') << std::setw (2) << time_info->tm_mday
		<< "_" << time_info->tm_hour << time_info->tm_min
		<< time_info->tm_sec << "]";
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << p_amount << ";deposit:" << deposit
		<< ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << p_amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused\n";
		return false;
	}
	_amount = _amount - withdrawal;
	_totalAmount = _totalAmount - withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return true;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << "\n";
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << "\n";
}
