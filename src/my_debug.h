#ifndef MY_DEBUG_H_
#define MY_DEBUG_H_

namespace my
{
  void dbgprint(const char *filepath, int lineno, const char *funcname,
                const char *fmt, ...);
} // namespace my

#endif // MY_DEBUG_H_