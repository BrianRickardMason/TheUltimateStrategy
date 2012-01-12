
#ifndef _MODERATORCONTEXTBUILDER_H_
#define _MODERATORCONTEXTBUILDER_H_

#include "ModeratorContext.h"

class ModeratorContextBuilder {
public:
    ModeratorContextBuilder();
    ~ModeratorContextBuilder();
    
    void make();
    
    void fillDefault();
    
    ModeratorContext& peek();
    
    IModeratorContext::Handle extract();
private:
    std::auto_ptr<ModeratorContext> mContext;
    
    const std::string LOCALHOST;
    const std::string DEFAULT_MODERATOR_LOGIN;
    const std::string DEFAULT_MODERATOR_PASSWORD;
};

#endif
