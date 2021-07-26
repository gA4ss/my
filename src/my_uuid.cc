#include <my_uuid.h>
#include <uuid/uuid.h>

#include <iostream>
#include <sstream>
#include <iomanip>

namespace my {

static const unsigned char kZeroChar = 48;

std::string uuid() {
  uuid_t id;
  uuid_generate(id);

  std::stringstream ss;
  ss << std::hex << std::setw(2) 
     << id[0] + kZeroChar << id[1] + kZeroChar << id[2] + kZeroChar << id[3] + kZeroChar
     << id[4] + kZeroChar << id[5] + kZeroChar << id[6] + kZeroChar << id[7] + kZeroChar
     << id[8] + kZeroChar << id[9] + kZeroChar << id[10] + kZeroChar << id[11] + kZeroChar
     << id[12] + kZeroChar << id[13] + kZeroChar << id[14] + kZeroChar << id[15] + kZeroChar;
  return ss.str();
}

} // namespace my