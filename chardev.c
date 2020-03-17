#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/sched.h>

#define MAJORNO 300
#define MINORNO 0
#define CHAR_NAME "sriram"
#define MAX_SIZE 2048

static dev_t first;
static int count = 0;
static struct cdev *mydev;
static char *kbuf;
static int inuse = 0;

static int open(struct inode *inode, struct file *filp)
{
	inuse++;
	printk(KERN_INFO"This device is opened by these many users %d\n",inuse);
	printk(KERN_INFO"The Majorno is %d and Minorno is %d\n",imajor(inode),iminor(inode));
	printk(KERN_INFO"
	return 0;
}

static ssize_t write(struct file *filp, const char __user *buf, size_t ln, loff_t *pos)
{
}

static ssize_t read(struct file *filp, char __user *buf, size_t ln, loff_t *pos)
{
}

static int close(struct inode *inode, struct file *filp)
{
	return 0;
}

static struct file_operations f_ops = {
	.owner	=	THIS_MOUDLE,
	.open	=	open,
	.write	=	write,
	.read	=	read,
	.release=	close,
};

static int __init start(void)
{
	first = MKDEV(MAJORNO,MINORNO);
	if(register_chrdev_region(first,count,CHAR_NAME) < 0)
	{
		printk(KERN_ERR"This device is not register in the kernel\n");
		return -EINVAL;
	}
	mydev = cdev_alloc();
	cdev_init(mydev,&f_ops);
	if(cdev_add(mydev,first,count) < 0)
	{
		printk(KERN_ERR"This device is not register in the kernel\n");
		return -EINVAL;
	}
	kbuf = (char*)kzalloc(MAX_SIZE,GFP_KERNEL);
	printk(KERN_INFO"This device is register with the name %s\n",CHAR_NAME);
	printk(KERN_INFO"The Majorno is %d and Minorno is %d\n",MAJOR(first),MINOR(first));
	return 0;
}

static void __exit stop(void)
{
	kfree(kbuf);
	cdev_del(mydev);
	unregister_chrdev_region(first,count);
	printk(KERN_INFO"This device is removed from the kernel\n");
}

module_init(start);
module_exit(stop);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("sriramdhivakar.M");
MODULE_VERSION("V0.1");
MODULE_DESCRIPTION("This module is used for character device driver");
