#include <linux/kernel.h>
#include <linux/module.h>

static int value = 1;
static void func(void);

EXPORT_SYMBOL_GPL(value);
EXPORT_SYMBOL_GPL(func);

static void func(void)
{
	printk(KERN_INFO"The value is %d\n",value);
}

static int __init start(void)
{
	func();
	return 0;
}

static void __exit stop(void)
{
	printk(KERN_INFO"Bye...\n");
}

module_init(start);
module_exit(stop);

MODULE_VERSION("V0.1");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sriramdhivakar.M");
MODULE_DESCRIPTION("This module is based on the symbol table"); 
