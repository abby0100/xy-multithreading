#include <iostream>
#include <thread>
#include <unistd.h>
#include <time.h>

#include "xylog.h"

using namespace std;


void hello_multithread() {
	xy_print("Hello world, multithread.\n");
	return;
}

class xy_task {
public:
	void operator()() const {
		xy_print("Hello world, xy_task.\n");
		return;
	}
};

int main() {

	xy_print("Hello world.\n");
	//xy_print_simple("Hello world.\n");

	thread t1(hello_multithread);
	t1.join();
	
	xy_task task;
	thread t2(task);
	t2.join();

	thread t3{ xy_task() };
	t3.join();

	thread t4([]{
		xy_print("Hello world, anonymous.\n");
	});
	t4.join();
}
