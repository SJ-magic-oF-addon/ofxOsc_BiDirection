/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

#include "ofxOsc.h"

/************************************************************
class
************************************************************/

/**************************************************
**************************************************/
class OSC_SEND{
private:
	enum{
		BUF_SIZE = 512,
	};
	
	char IP[BUF_SIZE];
	int Port;

	ofxOscSender sender;
	
	/****************************************
	noncopyable
	****************************************/
	void operator =(const OSC_SEND& src);
	OSC_SEND(const OSC_SEND& src);
	
	void _setup(const char* _IP, int _Port)
	{
		if(_Port != -1){
			sprintf(IP, "%s", _IP);
			Port = _Port;
			
			sender.setup(IP, Port);
		}
	}
	
public:
	OSC_SEND()
	: Port(-1)
	{
	}
	
	OSC_SEND(const char* _IP, int _Port)
	{
		_setup(_IP, _Port);
	}
	
	void setup(const char* _IP, int _Port)
	{
		_setup(_IP, _Port);
	}
	
	void sendMessage(ofxOscMessage &message, bool wrapInBundle = true)
	{
		if(Port != -1){
			sender.sendMessage(message, wrapInBundle);
		}
	}
};

/**************************************************
**************************************************/
class OSC_RECEIVE{
private:
	int Port;
	ofxOscReceiver	receiver;
	
	/****************************************
	noncopyable
	****************************************/
	void operator =(const OSC_RECEIVE& src);
	OSC_RECEIVE(const OSC_RECEIVE& src);
	
	void _setup(int _Port)
	{
		if(_Port != -1){
			Port = _Port;
			receiver.setup(Port);
		}
	}
	
public:
	OSC_RECEIVE()
	: Port(-1)
	{
	}
	OSC_RECEIVE(int _Port)
	{
		_setup(_Port);
	}
	
	void setup(int _Port)
	{
		_setup(_Port);
	}
	
	bool hasWaitingMessages()
	{
		if(Port == -1){
			return false;
		}else{
			return receiver.hasWaitingMessages();
		}
	}
	
	bool getNextMessage(ofxOscMessage& msg)
	{
		if(Port == -1)	return false;
		else			return receiver.getNextMessage(msg);
	}
	
	bool getNextMessage(ofxOscMessage* msg)
	{
		if(Port == -1)	return false;
		else			return receiver.getNextMessage(msg);
	}
};

/**************************************************
**************************************************/
class OSC_TARGET{
private:
	/****************************************
	noncopyable
	****************************************/
	void operator =(const OSC_TARGET& src);
	OSC_TARGET(const OSC_TARGET& src);
	
public:
	OSC_SEND	OscSend;
	OSC_RECEIVE	OscReceive;
	
	OSC_TARGET()
	{
	}
	
	OSC_TARGET(const char* _SendTo_IP, int _SendTo_Port, int _Receive_Port)
	: OscSend(_SendTo_IP, _SendTo_Port), OscReceive(_Receive_Port)
	{
	}
	
	void setup(const char* _SendTo_IP, int _SendTo_Port, int _Receive_Port)
	{
		OscSend.setup(_SendTo_IP, _SendTo_Port);
		OscReceive.setup(_Receive_Port);
	}
};


