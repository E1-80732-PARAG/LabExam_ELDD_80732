// export

#include <linux/module.h>
#include <linux/kfifo.h>
#include <linux/moduleparam.h>

int ret;
//===========================================================
// 1) a. Pass kfifo size as module parameter.
int kfifo_size = 1;
module_param(kfifo_size, int, 0644);

//===========================================================

struct kfifo my_kfifo;
//===========================================================
//===========================================================
//===========================================================



static __init int export_init(void)
{
	printk(KERN_INFO " %s : export_init() function start \n", THIS_MODULE->name);
	printk(KERN_INFO " %s :   size = %d \n", THIS_MODULE->name, kfifo_size);
	
	// 2) In init, create a kernel fifo with given size, if size is less than 1024 bytes. If size is more than 1024 return error.
	if(kfifo_size > 1024 )
	{
		printk(KERN_ERR " %s : kfifo size is greater than 1024 \n", THIS_MODULE->name);
		return -1;
	}
	
	// kfifo allocation
	ret = kfifo_alloc(&my_kfifo, kfifo_size , GFP_KERNEL);
	if(ret < 0)
	{
		printk(KERN_ERR " %s : kfifo alloc is failed\n", THIS_MODULE->name);
		return -1;
	}
	
	


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



