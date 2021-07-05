#include <my_uuid.h>

#include <uuid/uuid.h>
#include <cstring>

namespace my {

std::string uuid() {
  uuid_t id;
  uuid_generate(id);  

  char buf[128] = {0};
  sprintf(buf, "%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X-%02X",
                id[0], id[1], id[2], id[3], id[4], 
                id[5], id[6], id[7], id[8], id[9], 
                id[10], id[11], id[12], id[13], 
                id[14], id[15]);
  std::string ret = buf;
  return ret;
}

} // namespace my