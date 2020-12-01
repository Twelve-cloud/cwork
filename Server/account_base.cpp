#include "streamtable.h"
#include "account_base.h"
#include "account.h"
#include <iostream>
#include <algorithm>

extern StreamTable st;

bool compare(const Account* obj1, const Account* obj2) // функция для сортировки
{
    return obj1 -> getLogin() > obj2 -> getLogin();
}

void AccountBase::addObject(Account* object)
{
    std::cin >> *object;
    push_back(object);
    std::cout << "Account successfully added." << std::endl;
}

void AccountBase::remObject(const std::string &login)
{
    uint32_t index = -1;
    if (findObject(login, index))
    {
        erase(begin() + index);
        std::cout << "Account successfully deleted." << std::endl;
    }
    else
    {
        std::cout << "Account with this login not found." << std::endl;
    }
}

void AccountBase::changeObject(const std::string& login)
{
    uint32_t index = -1;
    if (findObject(login, index))
    {
        std::cin >> *(*this)[index];
        std::cout << "Data of this account is successuly changed." << std::endl;
    }
    else
    {
        std::cout << "Account with this login not found." << std::endl;
    }
}

bool AccountBase::findObject(const std::string& login, std::uint32_t& index)
{
    for (const auto& obj : *this)
    {
        index++;
        if (obj -> getLogin() == login)
            return true;
    }

    return false;
}

bool AccountBase::findObject(const std::string& login)
{
    for (const auto& obj : *this)
    {
        if (obj -> getLogin() == login)
            return true;
    }

    return false;
}

bool AccountBase::findObject(const std::string& login, const std::string& password)
{
    for (const auto& obj : *this)
    {
        if (obj -> getLogin() == login && obj -> getPassword() == password)
            return true;
    }

    return false;
}

void AccountBase::filltration(const std::string &data)
{
    system("cls");
    st.firstCell(true);
    std::cout << "Enter data: ";
    for (char ch : data)
    {
        putchar(ch);
    }

    for (const auto& obj : *this)
    {
        if (!obj -> getLogin().compare(0, data.size(), data))
        {
            std::cout << *obj;
            continue;
        }
        if (!obj -> getPassword().compare(0, data.size(), data))
        {
            std::cout << *obj;
            continue;
        }
    }
}

void AccountBase::sort()
{
    std::sort(begin(), end(), compare);
}

void AccountBase::readFile()
{
    std::string login, password;

    m_fstream.open(m_filename, std::ios_base::in);

    while (m_fstream >> login >> password)
    {
        Account* object = new Account(login, password);
        push_back(object);
        if (m_fstream.eof()) break;
    }

    m_fstream.close();
}

void AccountBase::rewrite()
{
    m_fstream.open(m_filename, std::ios_base::out);

    for (const auto& object : *this)
    {
        m_fstream << object -> getLogin() << std::endl << object -> getPassword() << std::endl;
    }

    m_fstream.close();
}

std::ostream& operator<<(std::ostream& out, const AccountBase& m_base)
{
    st.firstCell(true);
    for (const auto& obj : m_base)
    {
        std::cout << *obj;
    }

    return out;
}