#include <linux/module.h>
#include <linux/kernel.h>

static int rollno = 1;
module_param(rollno,int,S_IRWXU);
MODULE_PARM_DESC(rollno,"This value is display in the kernel");

static char *name = "sriram";
module_param(name,charp,S_IRWXU);
MODULE_PARM_DESC(name,"This name is display in the kernel");

static int a[2] = {-1,1};
static int arg = 0;
module_param_array(a,int,&arg,S_IRWXU);
MODULE_PARM_DESC(a,"This array is display in the kernel");

static int __init start(void)
{
	int i;
	printk(KERN_INFO"The Rollno %d name is %s\n",rollno,name);

	for(i=0;i<sizeof(a)/sizeof(int);i++)
	{
		printk(KERN_INFO"The a[%d] is %d\n",i,a[i]);
	}

	printk(KERN_INFO"The argument is %d\n",arg);
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
MODULE_DESCRIPTION("This module is used to explain the module parameter");
