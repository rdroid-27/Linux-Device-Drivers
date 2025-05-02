#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("rdroid-27 - Rachit");

static struct proc_dir_entry *proc_entry;

static ssize_t counter_read(struct file *file_pointer, char *user_space_buffer, size_t count, loff_t *offset)
{
    char mesg[] = "Ack!\n";
    size_t len = strlen(mesg);
    printk("Counter Read\n");
    int result = copy_to_user(user_space_buffer, mesg, len);
    if (*offset >= len)
        return 0;
    *offset += len;
    return len;
}

static struct proc_ops driver_proc_ops{
    .proc_read = counter_read};

static int counter_module_init(void)
{
    printk("counter_module_init: Entry\n");
    proc_entry = proc_create("counter_ldd", 0, NULL, &driver_proc_ops);
    if (proc_entry == NULL)
    {
        printk("counter_module_init: Error\n");
        return -1;
    }
    printk("counter_module_init: Exit\n");

    return 0;
}

static void counter_module_exit(void)
{
    printk("counter_module_exit: Entry\n");
    proc_remove(proc_entry);
    printk("counter_module_exit: Exit\n");
}

module_init(counter_module_init);
module_exit(counter_module_exit);
