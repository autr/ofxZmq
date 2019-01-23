#pragma once

#include "ofMain.h"
#include "ofxZmq.h"

class ofxZmqRequest : public ofxZmqSocket
{
public:
	
	ofxZmqRequest();
	
	void connect(string addr);
	
	bool send(void *data, size_t len, bool nonblocking = false, bool more = false);
	bool send(string &data, bool nonblocking = false, bool more = false);
	bool send(ofBuffer &data, bool nonblocking = false, bool more = false);

	bool receive(string &data);
	bool receive(ofBuffer &data);
	
	bool hasWaitingMessage(long timeout_millis = 0);
	bool getNextMessage(string &data);
	bool getNextMessage(ofBuffer &data);
	
};
