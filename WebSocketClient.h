#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <WiFiClient.h>

class WebSocketClient {
public:

	WebSocketClient(bool secure = false);

	~WebSocketClient();

	bool connect(String host, String path, int port);

	bool isConnected();

	void disconnect();

	void send(const String& str);

	bool getMessage(String& message);

	void addHeader(String header, String value);

	WiFiClient *client;

private:
	int timedRead();

    void write(uint8_t data);
    
    void write(const char *str);

	String generateKey();

	String additionalHeaders = "";

    bool websocketEstablished = false;

};

#endif //WEBSOCKETCLIENT_H
