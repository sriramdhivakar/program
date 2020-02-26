#include <linux/kernel.h>
#include <linux/module.h>


int init_module(void)
{
	printk(KERN_INFO"This module is very basic version\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO"bye..\n");
}

MODULE_VERSION("V0.1");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sriramdhivakar.M");
MODULE_DESCRIPTION("This module is based on the old method");
