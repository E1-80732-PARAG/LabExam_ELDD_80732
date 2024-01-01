// export

#include <linux/module.h>
#include <linux/kfifo.h>
#include <linux/moduleparam.h>

int kfifo_size = 1;
module_param(kfifo_size, int, 0644);


static __init int export_init(void)
{
	printk(KERN_INFO " %s : export_init() function start \n", THIS_MODULE->name);
	printk(KERN_INFO " %s :   size = %d \n", THIS_MODULE->name, kfifo_size);

	return 0;
}

static __exit void export_exit(void)
{
	printk(KERN_INFO " %s : export_exit() function start \n", THIS_MODULE->name);
	

}

module_init(export_init);
module_exit(export_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PARAG B PATIL 80732");
MODULE_DESCRIPTION("Linux device driver lab exam --> export section");



