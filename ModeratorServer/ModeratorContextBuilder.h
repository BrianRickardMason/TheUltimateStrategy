
#ifndef _MODERATORCONTEXTBUILDER_H_
#define _MODERATORCONTEXTBUILDER_H_

#include "ModeratorContext.h"

/// TODO revert wtf valgrind debugging
#include "wtf.h"

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
    
    const wtf::string LOCALHOST;
    const wtf::string DEFAULT_MODERATOR_LOGIN;
    const wtf::string DEFAULT_MODERATOR_PASSWORD;
};

#endif
