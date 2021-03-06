
/***********************************************
  File name		: server.h
  Create date	: 2015-12-02 22:04
  Modified date : 2016-01-15 09:08
  Author		: zmkeil, alibaba.inc
  Express : 
  
 **********************************************/
#ifndef NRPC_SERVER_H
#define NRPC_SERVER_H
#include <vector>
#include <string>
#include "service_set.h"
#include "service_context.h"

namespace nrpc {

struct ServerOption {
    ServerOption() :
            read_timeout(3/*s*/),
            is_connection_reuse(false),
            idle_timeout(3),
            write_timeout(3),
            max_concurrency(8),
            service_context_factory(nullptr) {}

    // read request timeout
    int read_timeout;
    // is connection reused?
    bool is_connection_reuse;
    // idle timeout before reused
    int idle_timeout;
    // send response timeout
    int write_timeout;
    // max concurrency
    int max_concurrency;
    // context factory, create context for pre-session
    ServiceContextFactory* service_context_factory;
};

class Server {
public:
	Server();
	~Server();

    // new ServiceSet, and push_back to service_sets
    ServiceSet* push_service_set(const std::string& str_address
                    /*host:port:bind:wildcard:so_keepalive*/);

    // Start server
    int start(ServerOption* option);

	// Stop server
	int stop();

	// Join all processor after server.stop()
	int join();


    // get options
    int read_timeout();
    bool is_connection_reuse();
    int idle_timeout();
    int write_timeout();
	// concurrency limit is implemented through a simple counter.
	// because nginx is signal thread, no mutex is needed.
	bool get_concurrency();
	void free_concurrency();
    ServiceContext* local_service_context();

private:
    ServerOption* _option;
    std::vector<ServiceSet*> _service_sets;
};

}
#endif
