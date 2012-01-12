
#ifndef _WTF_H_
#define _WTF_H_

#include <string>
#include <iostream>

namespace wtf {
    class string: public std::string {
    public:
        string(const char* s): std::string(s){
            std::clog << "+wtf = " << this << " s = " 
                << (unsigned)static_cast<std::string&>(*this).c_str() << "/" 
                << static_cast<std::string&>(*this) << "/" 
                << (unsigned)s 
            << std::endl;
        }
        ~string(){
            std::clog << "-wtf = " << this << " s = " 
                << (unsigned)static_cast<std::string&>(*this).c_str() << "/" 
                << static_cast<std::string&>(*this) 
            << std::endl;
        }
    };
}

#endif
