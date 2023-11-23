#include <my_common.h>

#ifndef OS_LINUX
#include <unistd.h>
#endif

#include <fstream>

namespace my {

void tokenize(std::string const& str, std::vector<std::string>& out, std::string delims) {
  char *token = strtok(const_cast<char*>(str.c_str()), delims.c_str());
  while (token) {
    out.push_back(token);
    token = strtok(nullptr, delims.c_str());
  }
}

std::string get_filename(std::string path) {
  return path.substr(path.find_last_of('/')+1);
}

std::string get_real_path(const std::string& path) {
  char resolved_path[2048] = {0};
  if (path[0] == '~') {
    const char* home = getenv("HOME");
    strcpy(resolved_path, home);
    char buffer[2048] = {0};
    strcpy(buffer, path.c_str());
    strcat(resolved_path, buffer+1);
  } else {
    return realpath(path.c_str(), resolved_path);
  }
  return resolved_path;
}

size_t get_filesize(std::string path) {
  std::ifstream in(path, std::ios::in|std::ios::binary|std::ios::ate);  
  size_t size = in.tellg();
  in.close(); 
  return size;
}

int read_file(std::string path, std::string& txt) {
  std::string apath = get_real_path(path);
  std::fstream in(apath, std::ios::in | std::ios::binary | std::ios::ate);  
  if (!in.is_open()) {
    return ERROR_OPEN_FILE;
  }
  
  size_t size = in.tellg();
  char* buffer = new char [size+1];
  assert(buffer);
  memset(buffer, 0, size+1);
  in.seekg(0, std::ios::beg);
  in.read (buffer, size);
  in.close();

  txt = buffer;
  delete [] buffer;
  return ERROR_SUCCEE;
}

bool get_environment_variable(std::string &str, const char* environment_variable) {
  char* env_var_cstr = NULL;
#ifdef _MSC_VER
    _dupenv_s(&env_var_cstr, NULL,environment_variable);
#else
    env_var_cstr = getenv(environment_variable);
  #endif
  if ( env_var_cstr ) {
    str = std::string(env_var_cstr);
#ifdef _MSC_VER
    free(env_var_cstr);
#endif
    return true;
  } else {
    str = std::string("");
    return false;
  }
}

std::string str_to_hex(const std::string& data, bool bigcase)
{
  const std::string hex = !bigcase ? "0123456789abcdef" : "0123456789ABCDEF";
  std::stringstream ss;

  for (std::string::size_type i = 0; i < data.size(); ++i)
    ss << hex[(unsigned char)data[i] >> 4] << hex[(unsigned char)data[i] & 0xf];
  // std::cout << ss.str() << std::endl;
  return ss.str();
}

std::string hex_to_str(const std::string& str)
{
  std::string result;
  for (size_t i = 0; i < str.length(); i += 2)
  {
    std::string byte = str.substr(i, 2);
    char chr = (char)(int)strtol(byte.c_str(), nullptr, 16);
    result.push_back(chr);
  }
  return result;
}

} // namespace my