/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:44:16 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/06 11:28:46 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(void)
{
    _accountIndex = getNbAccounts();
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount
              << ";created\n";
    Account::_nbAccounts++;
}

Account::Account(int initial_deposit)
{
    _accountIndex = getNbAccounts();
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount
              << ";created\n";
    Account::_nbAccounts++;
    Account::_totalAmount += _amount;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount
              << ";closed\n";
}

int  Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int  Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int  Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int  Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() 
              << ";total:" <<  getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount +=deposit;
    std::cout << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";
    if (_amount - withdrawal >= 0)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << withdrawal
                  << ";amount:" << _amount
                  <<";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    std::cout << "refused" << std::endl;
    return (false);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t now;
    std::tm     *timeInfo;
    char        buffer[19];
    
    now = std::time(NULL);
    timeInfo = std::localtime(&now);
    std::strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", timeInfo);
    std::cout << buffer;
}