#ifndef __GENERIC_IPBUS_DEVICE_HPP__
#define __GENERIC_IPBUS_DEVICE_HPP__

//For tool device base class
#include <BUTool/CommandList.hh>
#include <BUTool/DeviceFactory.hh>

#include <string>
#include <vector>

#include <uhal/uhal.hpp>

#include <iostream>
#include <fstream>

#include <IPBusRegHelper/IPBusRegHelper.hh>

#include <GenericIPBus/GenericIPBus.hh>

namespace BUTool{

  //This holder class is used to force the GenericIPBus class that would normally
  //be in the GenericIPBusDevice class to be initialized before the IPBusRegHelper
  //so that it can be past to the IPBusRegHelper's constructor. 
  class GenericIPBusHolder{
  public:
    GenericIPBusHolder(std::vector<std::string> const & arg){
      SM = std::make_shared<GenericIPBus>(arg);
    };
  protected:
    std::shared_ptr<GenericIPBus> SM;
  private:
    GenericIPBusHolder();
  };

  
  class GenericIPBusDevice: public CommandList<GenericIPBusDevice>,
			    public GenericIPBusHolder,
			    public IPBusRegHelper{
  public:
    GenericIPBusDevice(std::vector<std::string> arg); 
    ~GenericIPBusDevice();




  private:

    //Here is where you update the map between string and function
    void LoadCommandList();

    //Add new command functions here
        
    //Add new command (sub command) auto-complete files here
    std::string autoComplete_Help(std::vector<std::string> const &,std::string const &,int);

    CommandReturn::status DumpDebug(std::vector<std::string>,std::vector<uint64_t>);

  };
  RegisterDevice(GenericIPBusDevice,
		 "GenericIPBus",
		 "file/SM_SN",
		 "g",
		 "GenericIPBus",
		 "\"connection file\"  or \"SM_SN\""
		 ); //Register GenericIPBusDevice with the DeviceFactory  
}

#endif
