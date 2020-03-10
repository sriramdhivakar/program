#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

#define shared_irq 28

static int irq = shared_irq;
module_param(irq,int,S_IRWXU);
MODULE_PARM_DESC(irq,"This value is display in the /var/log");

static int mydev = 100;
static int irqnumber;

static irqreturn_t intra(int irq,void *dev_id)
{
	irqnumber++;
	printk(KERN_INFO"The interrupt is occured in these many times %d\n",irqnumber);
	return IRQ_NONE;
}


static int __init start(void)
{
	if(request_irq(irq,intra,IRQF_SHARED,"myinterrupt",&mydev) < 0)
	{
		printk(KERN_ERR"This interrupt is not valid\n");
		return -EINVAL;
	}
	printk(KERN_INFO"The interrupt value is %d\n",irq);
	return 0;
}

static void __exit stop(void)
{
	free_irq(irq,&mydev);
	printk(KERN_INFO"Bye..\n");
}

module_init(start);
module_exit(stop);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_VERSION("V0.1");
MODULE_AUTHOR("sriramdhivakar.M");
MODULE_DESCRIPTION("This module is based on the interrupt");
