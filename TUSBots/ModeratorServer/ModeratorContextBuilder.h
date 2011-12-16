
#ifndef _MODERATORCONTEXTBUILDER_H_
#define _MODERATORCONTEXTBUILDER_H_
#include "ModeratorContext.h"

class ModeratorContextBuilder {
public:
    void make();
    
    void fillDefault();
    
    IModeratorContext::Handle extract();
private:
    std::auto_ptr<ModeratorContext> mContext;
};

#endif
