#ifndef NETWORK_NETWORK_BA_H
#define NETWORK_NETWORK_BA_H

#include "network.h"

// inheritance
class NetworkMDA: public Network{
    int _m{1};


public:
    NetworkMDA(int m=1);


};

#endif // NETWORK_NETWORK_BA_H

