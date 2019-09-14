#ifndef __XY_LOG_H__
#define	__XY_LOG_H__

#include <unistd.h>

#define xy_print_base(format, args...) {					\
	printf(format, ##args);									\
}

#define xy_print_time(format, args...) {					\
	time_t timep;											\
	time(&timep);											\
	struct tm *t = gmtime(&timep);							\
	xy_print_base("%4d-%02d-%02d %02d:%02d:%02d\t" format,	\
		t->tm_year+1900, t->tm_mon, t->tm_mday,				\
		t->tm_hour, t->tm_min, t->tm_sec, ##args)			\
}

#define xy_print_time_simple(format, args...) {				\
	time_t timep;											\
	time(&timep);											\
	struct tm *t = gmtime(&timep);							\
	xy_print_base("%02d:%02d:%02d\t" format,				\
		t->tm_hour, t->tm_min, t->tm_sec, ##args)			\
}

#define xy_print_pid(format, args...) {						\
	xy_print_time("%4d %d\t" format,getppid(), getpid(), ##args)			\
}

#define xy_print_pid2(format, args...) {					\
	xy_print_time_simple("%4d %4d\t" format, getppid(), getpid(), ##args)	\
}

#define xy_print_func(format, args...) {					\
	xy_print_pid("%s: " format, __func__, ##args)			\
}

#define xy_print_func2(format, args...) {					\
	xy_print_pid2("%s\t" format, __func__, ##args)			\
}

#define xy_print(format, args...) {							\
	xy_print_func(format, ##args)							\
}

#define xy_print_simple(format, args...) {					\
	xy_print_func2(format, ##args)							\
}

#endif
