#pragma once
#include "SocketAddress.h"


class UDPSocket
{
public:
	~UDPSocket() {};

	int Bind(const SocketAddress& inToAddress);

	int SendTo(const void* inData, int inLen, const SocketAddress& inTo);

	int ReceiveFrom(void* inBuffer, int inLen, SocketAddress& outFrom);

private:

	UDPSocket(SOCKET inSocket) :mSocket(inSocket) {}

	SOCKET mSocket;
};