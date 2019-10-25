#ifndef __GENERIC_IPBUS_HH__
#define __GENERIC_IPBUS_HH__

#include <IPBusIO/IPBusConnection.hh>
#include <BUException/ExceptionBase.hh>


#include <iostream>


#include <stdint.h>

class GenericIPBus : public IPBusConnection{
public:
  GenericIPBus(); //User should call Connect inhereted from IPBusConnection
  ~GenericIPBus();

  //The IPBus connection and read/write functions come from the IPBusConnection class.
  //Look there for the details. 

  void DebugDump(std::ostream & output = std::cout);

private:  
};


#endif
