#include "account.h"
#include "streamtable.h"
#include "sysfunction.h"
#include <iostream>
#include <QString>
#include <iomanip>
#include <climits>

extern StreamTable st;

std::ostream& operator<<(std::ostream& out, const Account& object)
{
    st << object.m_login;
    st << object.m_password;

    return out;
}
std::istream& operator>>(std::istream& in, Account& object)
{
    std::cout << Rus("Введите логин: ");  std::cin >> std::setw(15) >> object.m_login;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << Rus("Введите пароль: "); std::cin >> std::setw(15) >> object.m_password;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return in;
}
