#include <linux/module.h>
#include <linux/printk.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/string.h>

static struct kobject *skg_kobject;
static int skgdata;

static ssize_t skgdata_show (struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
  pr_info ("Show called\n");
  return sprintf (buf, "%d\n", skgdata);
}

static ssize_t skgdata_store (struct kobject *kobj, struct kobj_attribute *attr, const char *buf,size_t count)
{
  pr_info ("Store called\n");
  sscanf (buf, "%du", &skgdata);
  return count;
}


static struct kobj_attribute skgdata_attribute = __ATTR (skgdata, 0660, skgdata_show, skgdata_store);

static int __init mymodule_init (void)
{
  int error = 0;

  pr_info ("Kobject module loaded\n");


  skg_kobject = kobject_create_and_add ("mykobject_skg", kernel_kobj->parent);
  if (!skg_kobject)
    return -ENOMEM;
  else
    pr_info ("Kobject created\n");

  error = sysfs_create_file (skg_kobject, &skgdata_attribute.attr);
  if (error)
    {
      pr_info
	("failed to create the skgdata file in /sys/kernel/kobject_skg \n");
    }
  else
    {
      pr_info ("Created the skgdata file in /sys/kernel/kobject_skg \n");
    }

  return error;
}

static void __exit mymodule_exit (void)
{
  pr_info ("Kobject module unloaded\n");
  kobject_put (skg_kobject);
}

module_init (mymodule_init);
module_exit (mymodule_exit);
MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("SateeshKG");
MODULE_DESCRIPTION ("Kobject demo");
