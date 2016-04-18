#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "MultiplicationService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

//using namespace tutorial;

int main()
{
  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  MultiplicationServiceClient client(protocol);

  try {
    transport->open();
    cout << "connected." << endl;
    transport->close();  
  } catch(TException& tx) {
    cout << "Error:" << tx.what() << endl; 
  }
}
