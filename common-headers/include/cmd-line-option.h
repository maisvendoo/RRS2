#ifndef     CMD_LINE_OPTION_H
#define     CMD_LINE_OPTION_H

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
template <class T>
struct option_t
{
    T value;
    bool is_present;

    option_t()
        : value(T())
        , is_present(false)
    {

    }
};

#endif // CMD_LINE_OPTION_H
