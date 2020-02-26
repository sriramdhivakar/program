#include <linux/kernel.h>
#include <linux/module.h>

static int no __initdata = 1;

static int __init start(void)
{
	printk(KERN_INFO"The roll no is %d\n",no);
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
MODULE_DESCRIPTION("This module is based on the variable substitution");
