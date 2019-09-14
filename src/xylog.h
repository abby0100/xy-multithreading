#ifndef __XY_LOG_H__
#define	__XY_LOG_H__

#include <unistd.h>

#define xy_print_base(format, args...) {	\
	printf(format, ##args);					\
}

#define xy_print_time_simple(format, args...) {				\
	time_t timep;	\
	time(&timep);	\
	struct tm *t = gmtime(&timep);			\
	xy_print_base("[%02d:%02d:%02d]" format,\
		t->tm_hour, t->tm_min, t->tm_sec, ##args)			\
}

#define xy_print_time(format, args...) {	\
	time_t timep;	\
	time(&timep);	\
	struct tm *t = gmtime(&timep);			\
	xy_print_base("[%4d-%02d-%02d %02d:%02d:%02d]" format,	\
		t->tm_year+1900, t->tm_mon, t->tm_mday,				\
		t->tm_hour, t->tm_min, t->tm_sec, ##args)			\
}

#define xy_print_pid(format, args...) {		\
	xy_print_base("[%4d]" format, getpid(), ##args)		\
}

#endif
