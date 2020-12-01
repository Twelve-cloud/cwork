#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace SendingCodes
{
    enum Action
    {
        AUTHENTIFICATION,
        REGISTRATION,
        CREATE_DB,
        CONNECT_DB,
    };

    enum ReturnCode
    {
        FAIL_AUTHENTIFICATION,
        FAIL_REGISTRATION,
        SUCCESS_REGISTRATION,
        SUCCESS_AUTHENTIFICATION,
        DATABASE_CREATION_SUCCESS,
        DATABASE_CREATION_FAIL,
        DATABASE_CONNECTION_SUCCESS,
        DATABASE_CONNECTION_FAIL,
    };

}

namespace Color
{
    enum ConsoleColor
    {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHT_GRAY = 7,
        DARK_GRAY = 8,
        LIGHT_BLUE = 9,
        LIGHT_GREEN = 10,
        LIGHT_CYAN = 11,
        LIGHT_RED = 12,
        LIGHT_MAGENTA = 13,
        YELLOW = 14,
        WHITE = 15
    };
}

namespace Output
{
    enum Key
    {
        PAGE_UP = 72,
        PAGE_DOWN = 80,
        ENTER = 13,
        BACKSPACE = 8,
    };

    enum Range
    {
        RANGE_UP = 1,
        SERVER_RANGE_DOWN = 3,
        ACCOUNT_RANGE_DOWN = 8,
        TECH_BASE_RANGE_DOWN = 7,
        TECH_RANGE_DOWN = 8,
    };
}

namespace Error
{
    enum ErrorCodes
    {
        FAIL_OPEN = -2,
        FAIL_EXEC = -1,
    };
}

namespace Types
{
    enum Type
    {
        COMPUTER,
        MOBILE_PHONE,
        TV,
        TOASTER,
        COFFEE_MAKER,
        EL_KETTLE,
        FRIDGE,
        CONDITIONER,
        MICROWAVE,
        TYPE_RANGE_DOWN = 9,
    };
}

#endif // CONSTANTS_H
