#include <GenericIPBus/GenericIPBus.hh>
#include <fstream> //std::ofstream

GenericIPBus::GenericIPBus():IPBusConnection("GenericIPBus"){
    // give BUTool::RegisterHelper it's TextIO pointer
    SetupTextIO();
}

GenericIPBus::~GenericIPBus(){
}

