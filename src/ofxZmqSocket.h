#pragma once

#include "ofMain.h"

#include "zmq.hpp"

class ofxZmqSocket
{

public:

	virtual ~ofxZmqSocket();

	void setIdentity(string data);
	string getIdentity();

	bool isConnected();

	void setHighWaterMark(long maxQueueSize);
	void setSendHighWaterMark(long maxQueueSize);
	void setReceiveHighWaterMark(long maxQueueSize);

	long getHighWaterMark();
	long getSendHighWaterMark();
	long getReceiveHighWaterMark();

    
    static void freeBufferData(void *data, void *hint);
    static void freeData(void *data, void *hint);

	zmq::socket_t socket;
	zmq::pollitem_t items[1];

	ofxZmqSocket(int type);

	void connect(string addr);
	void bind(string addr);
	void disconnect(string addr);
	void unbind(string addr);

    bool sendBuffer(ofBuffer* buffer, bool nonblocking, bool more);
	bool send(void *data, size_t len, bool nonblocking, bool more);
	//bool send(string &data, bool nonblocking, bool more);
	//bool send(ofBuffer &data, bool nonblocking, bool more);
	
	bool receive(string &data);
	bool receive(ofBuffer &data);

	bool hasWaitingMessage(long timeout_millis = 0);
	
	// return true if has more flag
	bool getNextMessage(string &data);
	bool getNextMessage(ofBuffer &data);

};
