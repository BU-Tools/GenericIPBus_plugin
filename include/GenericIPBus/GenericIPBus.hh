#ifndef __GENERIC_IPBUS_HH__
#define __GENERIC_IPBUS_HH__

#include <IPBusIO/IPBusConnection.hh>
#include <IPBusIO/IPBusIO.hh>
#include <BUException/ExceptionBase.hh>


#include <iostream>


#include <stdint.h>

class GenericIPBus : public IPBusConnection,
		     public IPBusIO{
public:
  GenericIPBus(std::vector<std::string> const & args);
  ~GenericIPBus();

  //The IPBus connection and read/write functions come from the IPBusConnection class.
  //Look there for the details. 

  void DebugDump(std::ostream & output = std::cout);

private:  
};


#endif
