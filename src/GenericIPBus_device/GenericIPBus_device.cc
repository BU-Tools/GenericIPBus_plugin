#include "GenericIPBus_device/GenericIPBus_device.hh"
#include <BUException/ExceptionBase.hh>
#include <boost/regex.hpp>

//For networking constants and structs                                                                          
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h> //for inet_ntoa        

#include <ctype.h> //for isdigit

#include <iostream>
#include <iomanip>
#include <ctime>


#include <boost/algorithm/string/predicate.hpp> //for iequals

using namespace BUTool;

#include <GenericIPBus_device/Version.hh>
RegisterDevice(GenericIPBusDevice,
	       "GenericIPBus",
	       "file/SM_SN",
	       "g",
	       "GenericIPBus",
	       "\"connection file\"  or \"SM_SN\"",
	       VersionTracker(nVer,std::string(sVer),std::string(uri))
	       ); //Register GenericIPBusDevice with the DeviceFactory  



GenericIPBusDevice::GenericIPBusDevice(std::vector<std::string> arg)
  : CommandList<GenericIPBusDevice>("GenericIPBus"),
    GenericIPBusHolder(arg),
    IPBusRegHelper(std::static_pointer_cast<IPBusIO>(SM),
		   BUTool::CommandListBase::TextIO){

  //setup commands
  LoadCommandList();
}

GenericIPBusDevice::~GenericIPBusDevice(){
}

  
void GenericIPBusDevice::LoadCommandList(){
    // general commands (Launcher_commands)
    AddCommand("read",&GenericIPBusDevice::Read,
	       "Read from GenericIPBus\n"          \
	       "Usage: \n"                     \
	       "  read addr <count> <FLAGS>\n" \
	       "Flags: \n"                     \
	       "  D:  64bit words\n"           \
	       "  N:  suppress zero words\n",
	       &GenericIPBusDevice::RegisterAutoComplete);
    AddCommandAlias("r","read");

    AddCommand("readFIFO",&GenericIPBusDevice::ReadFIFO,
	       "Read from a FIFO\n"      \
	       "Usage: \n"               \
	       "  readFIFO addr count\n",
	       &GenericIPBusDevice::RegisterAutoComplete);
    AddCommandAlias("rf","readFIFO");

    AddCommand("readoffset",&GenericIPBusDevice::ReadOffset,
	       "Read from an offset to an address\n" \
	       "Usage: \n"                           \
	       "  readoffset addr offset <count>\n",
	       &GenericIPBusDevice::RegisterAutoComplete);
    AddCommandAlias("ro","readoffset");

	AddCommand("readconvert",&GenericIPBusDevice::ReadConvert,
	     "Read and convert register\n" \
	     "Usage: \n"                           \
	     "  readconvert reg\n",
	     &GenericIPBusDevice::RegisterAutoComplete);

    AddCommand("write",&GenericIPBusDevice::Write,
	       "Write to GenericIPBus\n"           \
	       "Usage: \n"                     \
	       "  write addr <data> <count> \n",
	       &GenericIPBusDevice::RegisterAutoComplete);
    AddCommandAlias("w","write");

    AddCommand("writeFIFO",&GenericIPBusDevice::WriteFIFO,
	       "Write to GenericIPBus FIFO\n"      \
	       "Usage: \n"                     \
	       "  writeFIFO addr data count\n",
	       &GenericIPBusDevice::RegisterAutoComplete);
    AddCommandAlias("wf","writeFIFO");

    AddCommand("writeoffset",&GenericIPBusDevice::WriteOffset,
	       "Write from an offset to an address\n"   \
	       "Usage: \n"                              \
	       "  writeoffset addr offset data count\n",
	       &GenericIPBusDevice::RegisterAutoComplete);
    AddCommandAlias("wo","writeoffset");


    AddCommand("nodes", &GenericIPBusDevice::ListRegs, 
	       "List matching address table items\n",
	       &GenericIPBusDevice::RegisterAutoComplete);

    AddCommand("dump_debug",&GenericIPBusDevice::DumpDebug,
	       "Dumps all registers to a file for debugging\n"\
	       "Send to D. Gastler\n"\
	       "Usage: \n"\
	       "  dump_debug\n");

}

CommandReturn::status GenericIPBusDevice::DumpDebug(std::vector<std::string> /*strArg*/,
						std::vector<uint64_t> /*intArg*/){
/*
  std::stringstream outfileName;
  outfileName << "Apollo_debug_dump_";  

  char buffer[128];
  time_t unixTime=time(NULL);
  struct tm * timeinfo = localtime(&unixTime);
  strftime(buffer,128,"%F-%T-%Z",timeinfo);
  outfileName << buffer;

  outfileName << ".dat";
  
  std::ofstream outfile(outfileName.str().c_str(),std::ofstream::out);
  outfile << outfileName.str() << std::endl;
  SM->DebugDump(outfile);
  outfile.close();
*/
  return CommandReturn::OK;
}


