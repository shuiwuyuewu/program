#include "http.h"

void HTTP::parser(string url){

    string::size_type idx = url.find(':');
    if( idx != string::npos){
        url = url.substr(idx+3);
    }
    idx = url.find('/');
    m_host = url.substr(0,idx);
    m_url  = url.substr(idx+1);

}

void HTTP::connect(){

}
#ifdef DEBUG
void HTTP::show() const{
    std::cout << "HOST: " << m_host << "\nURL: " << m_url << std::endl;
}
#endif
