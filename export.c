// export

#include <linux/module.h>
#include <linux/kfifo.h>
#include <linux/moduleparam.h>

int ret;
char str[3];
//===========================================================
// 1) a. Pass kfifo size as module parameter.
int k_size = 1;
module_param(k_size, int, 0644);

//===========================================================

struct kfifo my_kfifo;
//===========================================================
//3) Create global variables for kfifo size, kfifo length and kfifo available. Export all these variable from current module.
int k_len, k_avail;
//===========================================================
// 4) Create two functions which will add and remove character from kfifo with following prototype.and export them

void kfifo_push(char *ch)
{
	ret = kfifo_in(&my_kfifo, ch, 15);
	if(ret < 0)
	{
		printk(KERN_ERR " %s : kfifo push/in is failed\n", THIS_MODULE->name);
		
	}
	printk(KERN_INFO " %s : kfifo push/in is DONE\n", THIS_MODULE->name);

}

char* kfifo_pop(void)
{
	
	 ret = kfifo_out(&my_kfifo, str, 5);
	 if(ret < 0)
	 {
		printk(KERN_ERR " %s : kfifo pop/out is failed\n", THIS_MODULE->name);

	 }
 	printk(KERN_INFO " %s : kfifo pop/out is DONE\n", THIS_MODULE->name);
	return str;
	
}


//===========================================================



static __init int export_init(void)
{
	printk(KERN_INFO " %s : export_init() function start \n", THIS_MODULE->name);
	printk(KERN_INFO " %s :   size = %d \n", THIS_MODULE->name, k_size);
	
	// 2) In init, create a kernel fifo with given size, if size is less than 1024 bytes. If size is more than 1024 return error.
	if(k_size > 1024 )
	{
		printk(KERN_ERR " %s : kfifo size is greater than 1024 \n", THIS_MODULE->name);
		return -1;
	}
	
	// kfifo allocation
	ret = kfifo_alloc(&my_kfifo, k_size , GFP_KERNEL);
	if(ret < 0)
	{
		printk(KERN_ERR " %s : kfifo alloc is failed\n", THIS_MODULE->name);
		return -1;
	}

	
	printk(KERN_INFO " %s : export_init() function over \n", THIS_MODULE->name);


	k_len = kfifo_len(&my_kfifo);
        k_avail = kfifo_avail(&my_kfifo);

	return 0;
}

//==================================================================================

static __exit void export_exit(void)
{
	printk(KERN_INFO " %s : export_exit() function start \n", THIS_MODULE->name);

	printk(KERN_INFO " %s : size of kfifo = %d , length of kfifo = %d, kfifo avail = %d\n", THIS_MODULE->name, k_size, k_len, k_avail);
	
	printk(KERN_INFO " %s : export_exit() function over \n", THIS_MODULE->name);
	

}

module_init(export_init);
module_exit(export_exit);

EXPORT_SYMBOL(k_size);
EXPORT_SYMBOL(k_len);
EXPORT_SYMBOL(k_avail);

EXPORT_SYMBOL(kfifo_push);
EXPORT_SYMBOL(kfifo_pop);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("PARAG B PATIL 80732");
MODULE_DESCRIPTION("Linux device driver lab exam --> export section");



