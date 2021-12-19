#include <my_type.h>

#include <string>
#include <map>

namespace my {

std::map<std::string, int> g_type_base;
std::map<int, std::string> g_reverse_type_base;

void init_my_type_system() {
  registry_type("object");
}

int registry_type(const char* tname) {
  int tid = -1;
  if (g_type_base.find(tname) == g_type_base.end()) {
    tid = g_type_base.size();
    g_type_base[tname] = tid;
    g_reverse_type_base[tid] = tname;
  }
  return tid;
}

int query_type(const char* tname) {
  if (g_type_base.find(tname) == g_type_base.end()) return -1;
  return g_type_base[tname];
}

const char* query_type(int tid) {
  if (g_reverse_type_base.find(tid) == g_reverse_type_base.end()) return nullptr;
  return g_reverse_type_base[tid].c_str();
}

// const std::string class_name(const char * name) {
//   int status = -1;
//   char* clear_name = abi::__cxa_demangle(name, NULL, NULL, &status);
//   const char * const  demangled_name = (status == 0) ? clear_name : name;
//   std::string ret_val(demangled_name);
//   free(clear_name);
//   return ret_val;
// }

} // namespace my