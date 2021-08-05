#pragma once
#include "iostream"
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

#pragma comment(lib, "WS2_32")

/*
*ScoketµØÖ·;
*/
class SocketAddress
{
public:
	SocketAddress(uint32_t inAddress,uint16_t inPort)
	{
		GetAsScokAddrIn()->sin_family = AF_INET;
		GetAsScokAddrIn()->sin_addr.S_un.S_addr = htonl(inAddress);
		GetAsScokAddrIn()->sin_port = htons(inPort);
	}

	SocketAddress(const sockaddr& inSockAddr)
	{
		memcpy(&mSockAddr, &inSockAddr, sizeof(sockaddr));
	}

	size_t GetSize() const 
	{
		return sizeof(sockaddr); 
	}

	const sockaddr& GetSockAddr() const
	{
		return mSockAddr;
	}

private:
	sockaddr mSockAddr;

	sockaddr_in* GetAsScokAddrIn()
	{
		return reinterpret_cast<sockaddr_in*>(&mSockAddr);
	}
};

using SocketAddressPtr = std::shared_ptr<SocketAddress>;


/*
*ÓòÃû½âÎö.
*/

class SocketAddressFactory
{
public:
	static SocketAddressPtr CreateIPV4FromString(const std::string& inString)
	{
		auto pos = inString.find_last_of(':');
		std::string host, servive;
		if (pos != std::string::npos)
		{
			host = inString.substr(0, pos);
			servive = inString.substr(pos + 1);
		}
		else
		{
			host = inString;
			servive = "0";
		}

		addrinfo hint;
		memset(&hint, 0, sizeof(hint));
		hint.ai_family = AF_INET;

		addrinfo* result;
		int error = getaddrinfo(host.c_str(), servive.c_str(), &hint, &result);

		if (error != 0 && result != nullptr)
		{
			freeaddrinfo(result);
			return nullptr;
		}

		while (!result->ai_addr && result->ai_next)
		{
			result = result->ai_next;
		}
		if (!result->ai_addr)
		{
			freeaddrinfo(result);
			return nullptr;
		}


		auto toRet = std::make_shared<SocketAddress>(*result->ai_addr);

		freeaddrinfo(result);

		return toRet;
	}
};