#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_FA2018_A5P2
{
    cnPtrQueue::cnPtrQueue() : numItems(0) {}

    bool cnPtrQueue::empty() const
    {
        return outStack.empty() && inStack.empty();
    }

    cnPtrQueue::size_type cnPtrQueue::size() const { return numItems; }

    CNode* cnPtrQueue::front()
    {
        assert( !inStack.empty() || !outStack.empty() );
        if ( outStack.empty() )
            while ( !inStack.empty() ) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        return outStack.top();
    }

    void cnPtrQueue::pop()
    {
        assert( !inStack.empty() || !outStack.empty() );
        numItems--;
        if ( outStack.empty() )
            while ( !inStack.empty() ) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        outStack.pop();
    }

    void cnPtrQueue::push(CS3358_FA2018_A5P2::CNode *cnPtr)
    {
        numItems++;
        inStack.push(cnPtr);
    }
}
