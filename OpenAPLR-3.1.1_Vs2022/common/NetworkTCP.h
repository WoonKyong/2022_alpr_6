//------------------------------------------------------------------------------------------------
// File: NetworkTCP.h
// Project: LG Exec Ed Program
// Versions:
// 1.0 April 2017 - initial version
// Provides the ability to send and recvive UDP Packets for both Window and linux platforms
//------------------------------------------------------------------------------------------------
#ifndef NetworkTCPH
#define NetworkTCPH
#pragma comment (lib, "Ws2_32.lib")
#include <Winsock2.h>
#include <ws2tcpip.h>
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#define  CLOSE_SOCKET closesocket
#define  SOCKET_FD_TYPE SOCKET
#define  BAD_SOCKET_FD INVALID_SOCKET

#define AES_ENCRYPTION  (TRUE)     // decision for applying AES256 encryption
#define TCP_KEEPALIVE   (TRUE)     // decision for using TCP KEEPALIVE

//------------------------------------------------------------------------------------------------
// Types
//------------------------------------------------------------------------------------------------

typedef struct
{
 SOCKET_FD_TYPE ListenFd;
} TTcpListenPort;

typedef struct
{
 SOCKET_FD_TYPE ConnectedFd;
} TTcpConnectedPort;

//------------------------------------------------------------------------------------------------
//  Function Prototypes 
//------------------------------------------------------------------------------------------------
TTcpListenPort *OpenTcpListenPort(short localport);
void CloseTcpListenPort(TTcpListenPort **TcpListenPort);
TTcpConnectedPort *AcceptTcpConnection(TTcpListenPort *TcpListenPort, 
                       struct sockaddr_in *cli_addr,socklen_t *clilen);
TTcpConnectedPort *OpenTcpConnection(const char *remotehostname, const char * remoteportno);
void CloseTcpConnectedPort(TTcpConnectedPort **TcpConnectedPort);
ssize_t ReadDataTcp(TTcpConnectedPort *TcpConnectedPort,unsigned char *data, size_t length);
ssize_t BytesAvailableTcp(TTcpConnectedPort* TcpConnectedPort);
ssize_t WriteDataTcp(TTcpConnectedPort *TcpConnectedPort,const unsigned char *data, size_t length);
#endif
//------------------------------------------------------------------------------------------------
//END of Include
//------------------------------------------------------------------------------------------------




