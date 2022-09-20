#include <GenericIPBus/GenericIPBus.hh>
#include <fstream> //std::ofstream

GenericIPBus::GenericIPBus(std::vector<std::string> const & args):
  IPBusConnection("GenericIPBus",args),
  IPBusIO(      ((IPBusConnection*)this)->GetHWInterface()){
  //Set case sensistive
  SetCase(RegisterHelperIO::RegisterNameCase::CASE_SENSITIVE);

}

GenericIPBus::~GenericIPBus(){
}

