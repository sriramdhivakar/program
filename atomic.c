#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>


static int __init start(void)
{
	atomic_t t = ATOMIC_INIT(10);
	printk(KERN_INFO"The Value of the atomic is %d\n",atomic_read(&t));
	atomic_add(10,&t);
	printk(KERN_INFO"The Value of the atomic is %d\n",atomic_read(&t));
	atomic_sub(10,&t);
	printk(KERN_INFO"The Value of the atomic is %d\n",atomic_read(&t));
	return 0;
}

static void __exit stop(void)
{
	printk(KERN_INFO"Bye..\n");
}

module_init(start);
module_exit(stop);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sriramdhivakar.M");
MODULE_VERSION("V0.1");
MODULE_DESCRIPTION("This module is based on the atomic");
