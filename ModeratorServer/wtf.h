
#ifndef _WTF_H_
#define _WTF_H_

#include <string>
#include <iostream>

namespace wtf {
    class string: public std::string {
    public:
        string(const char* s): std::string(s){
            std::clog << "+wtf = " << this << " s = " 
                << (const void*)static_cast<std::string&>(*this).c_str() << "/" 
                << (const void*)static_cast<std::string&>(*this).data() << "/" 
                << static_cast<std::string&>(*this) << "/" 
                << (const void*)s 
            << std::endl;
        }
        ~string(){
            std::clog << "-wtf = " << this << " s = " 
                << (const void*)static_cast<std::string&>(*this).c_str() << "/" 
                << (const void*)static_cast<std::string&>(*this).data() << "/" 
                << static_cast<std::string&>(*this) 
            << std::endl;
        }
    };
}

#endif
