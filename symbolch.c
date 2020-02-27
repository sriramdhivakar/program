#include <linux/kernel.h>
#include <linux/module.h>

static int *p;

static int __init start(void)
{
	p = (int*)__symbol_get("value");
	if(p)
	{
		*p = 2;
		__symbol_put("value");
	}
	else
	{
		printk(KERN_ERR"This value is invalid\n");
		return -EINVAL;
	}
	return 0;
}

static void __exit stop(void)
{
	printk(KERN_INFO"Bye...\n");
}

module_init(start);
module_exit(stop);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_VERSION("V0.1");
MODULE_AUTHOR("sriramdhivakar.M");
MODULE_DESCRIPTION("This module is used to change the value of the symbol table");
