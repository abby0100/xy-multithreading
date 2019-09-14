#include <iostream>
#include <thread>
#include <unistd.h>
#include <time.h>

#include "xylog.h"

using namespace std;


void hello_multithread() {
}

int main() {

	xy_print_pid("START\n");
	xy_print_time("%s\n", __func__);
	xy_print_time_simple("%s\n", __func__);

	thread t(hello_multithread);
	t.join();
}
