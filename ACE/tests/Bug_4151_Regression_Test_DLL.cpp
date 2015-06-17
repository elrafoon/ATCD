#include "ace/Service_Object.h"
#include "ace/Stream.h"
#include "ace/Module.h"
#include "ace/svc_export.h"
#include "string"

using namespace std;

class ACE_Svc_Export Service : public ACE_Service_Object {
public:
	int init(int argc, char **argv) {
		if(argc > 0 && !strcmp(argv[0], "--fail")) {
			ACE_ERROR((LM_NOTICE, "Failing service %@ init\n", this));
			return -1;
		}
		else {
			ACE_ERROR((LM_NOTICE, "Succeeding service %@ init\n", this));
			return 0;
		}
	}

	int fini() {
		ACE_ERROR((LM_NOTICE, "Service %@ fini\n", this));
		return 0;
	}
};

ACE_FACTORY_DEFINE(ACE_Svc, Service);

extern "C" ACE_Svc_Export ACE_Stream<ACE_MT_SYNCH> *_make_Stream()
{
    return new ACE_Stream<ACE_MT_SYNCH>;
}

class ACE_Svc_Export Task : public ACE_Task<ACE_MT_SYNCH> {
public:
	int init(int argc, char **argv) {
		ACE_ERROR((LM_NOTICE, "%s task initialized\n", is_reader() ? "reader" : "writer"));
		return 0;
	}
};

extern "C" ACE_Svc_Export ACE_Module<ACE_MT_SYNCH> *_make_Module()
{
	return new ACE_Module<ACE_MT_SYNCH>("test-module", new Task, new Task);
}

