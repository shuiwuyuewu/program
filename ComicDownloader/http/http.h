#ifndef HTTP_H_INCLUDED
#define HTTP_H_INCLUDED

#include <string>

#ifdef DEBUG
#include <iostream>
#endif

using std::string;

class HTTP{

public:
    void parser(string url);
    void connect();
    #ifdef DEBUG
    void show() const;
    #endif
private:
    string m_host;
    string m_url;
};

#endif // HTTP_H_INCLUDED
