#include <linux/kernel.h>
#include <linux/module.h>

static int __init start(void)
{
	printk(KERN_INFO"This is sriramdhivakar from kernel side\n");
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
MODULE_AUTHOR("sriramdhivakar.M");
MODULE_DESCRIPTION("This module is based on the new method");
