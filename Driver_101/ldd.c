#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("rdroid-27 - Rachit");

static int counter_module_init (void){
    printk("Hello, World!\n");
    return 0;
}

static void counter_module_exit (void){
    printk("Good Bye!\n");
}

module_init(counter_module_init);
module_exit(counter_module_exit);
