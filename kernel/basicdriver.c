#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
static int hello_module(void)
{
	pr_info("my basic module is\n");
	pr_info("loaded successfully\n");
	return 0;
}
static void hello_exit_module(void)
{
	printk(KERN_INFO"my basic module is \n");
	printk(KERN_INFO"offloaded successfully\n");
}
module_init(hello_module);
module_exit(hello_exit_module);
MODULE_AUTHOR("AJAY");
MODULE_LICENSE("GPLv2");
MODULE_DESCRIPTION("Basic model");
