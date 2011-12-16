#include <vector>

class IResponseHandler;

class IRequestHandler {
public:
    typedef std::vector<char> Request;
    
    void handleRequest(ResponseHandler& aCaller, const Request& aRequest);
};
