#include <linux/sched/signal.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/current.h>

static int __init start(void)
{
	struct task_struct *task;
	for_each_process(task){
		printk(KERN_INFO"Process name is %s,Process id is %d,Process state is %ld\n",task->comm,task->pid,task->state);
	}
	printk(KERN_INFO"Process name is %s,Process id is %d,Process state is %ld\n",current->comm,current->pid,task->state);
	return 0;
}

static void __exit stop(void)
{
	printk(KERN_INFO"Bye..\n");
}

module_init(start);
module_exit(stop);

MODULE_VERSION("V0.1");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sriramdhiavkar.M");
MODULE_DESCRIPTION("This module is based on the process display");
