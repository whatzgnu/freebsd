#ifndef _LINUX_STOP_MACHINE
#define _LINUX_STOP_MACHINE

#include <linux/cpu.h>
#include <linux/cpumask.h>
#include <linux/smp.h>
#include <linux/list.h>

struct cpumask;
typedef int (*cpu_stop_fn_t)(void *arg);

static inline int
stop_machine(cpu_stop_fn_t fn, void *data, const struct cpumask *cpus)
{
	int ret;
	sched_pin();
	ret = fn(data);
	sched_unpin();
	return (ret);
}

#endif
