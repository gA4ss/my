#ifndef MY_MY_ERROR_H_
#define MY_MY_ERROR_H_

#define ERROR_SUCCEE                                   0
#define ERROR_FAILED                                  -1
#define ERROR_WARNING                                 -2

//
// Basic
//
#define ERROR_OPEN_FILE                               0xFFFF0001
#define ERROR_CREATE_THREAD                           0xFFFF0002
#define ERROR_FILE_NOT_EXISTED                        0xFFFF0003

//
// Socket
//
#define ERROR_OPEN_SOCKET                             0xFFFE0001
#define ERROR_CONNECT_SOCKET                          0xFFFE0002
#define ERROR_BIND_SOCKET                             0xFFFE0003
#define ERROR_LISTEN_SOCKET                           0xFFFE0004
#define ERROR_SEND_SOCKET                             0xFFFE0005
#define ERROR_POLL_SOCKET                             0xFFFE0006
#define ERROR_RECVFROM_SOCKET                         0xFFFE0007

#endif // MY_MY_ERROR_H_