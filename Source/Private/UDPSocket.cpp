#include "../Public/UDPSocket.h"
#include "../Public/SocketUtil.h"

int UDPSocket::Bind(const SocketAddress& inToAddress)
{
	int err = bind(mSocket, &inToAddress.GetSockAddr(), inToAddress.GetSize());
	if (err != 0)
	{
		SocketUtil::ReportError("UDPSocket::Bind err =", err);
	}
	return err;
}

int UDPSocket::SendTo(const void* inData, int inLen, const SocketAddress& inTo)
{
	return 0;
}

int UDPSocket::ReceiveFrom(void* inBuffer, int inLen, SocketAddress& outFrom)
{
	return 0;
}
