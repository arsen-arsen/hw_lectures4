#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;


int main(){

class Protocol
{
    public:
	    virtual void send(char *buf, int len){};
};
class HexProtocol : public Protocol
{
    public:
	    void sendl(char *buf, int len)
	{
		for (int i = 0; buf[i] != '\0'; i++)
			cout << "0x" << hex << (int)(buf[i] & 0xff) << ' ';
	}
};


class BinaryProtocol : public Protocol
{
    public:
	    void sendl(char *buf, int len)
	{
		for (int i = 0; buf[i] != '\0'; i++)
		{
			bitset<8> x(buf[i]);
			cout << x << ' ';
		}
	}
};

void Filesread()
{
	string text = "software.txt", line;
	vector <string> protocols;
	fstream file;
	file.open(text);
	
	while (file >> line)
	{
		protocols.push_back(line);
	}
	file.close();

	Protocol **p = new Protocol *[protocols.size()];
	for (int i = 0; i < protocols.size(); i++)
	{
		if(protocols[i] == "HexProtocol")
        {
            p[i] = new HexProtocol;
        } 
		else if(protocols[i] == "BinaryProtocol")
        {
            p[i] = new BinaryProtocol;
        } 
        else
        {
            cout << " char unknown \n";
            exit(0);
        }
	}
	sendAll(p, protocols.size());
	delete[] p;
}
	return 0;
}
