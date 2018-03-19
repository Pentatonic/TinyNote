#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h> // For the character driver support
#include <linux/string.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

int simple_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

ssize_t simple_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{

    char *s = "Good day, sir!\n";
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    printk(KERN_ALERT "%s: length=%lu\n", __FUNCTION__, length);
    snprintf(buffer, length, "%s", s);

    return strlen(s);
}

ssize_t simple_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
    char *p = NULL;
    int i = 0;
    p = kmalloc(length + 1, GFP_KERNEL);

    if (!p)
        return 0;

    memset(p, 0x0, length + 1);
    memcpy(p, buffer, length);

    printk(KERN_ALERT "%s: length=%lu\n", __FUNCTION__, length);
    for (i = 0; i < length + 1; i++) {
        printk(KERN_ALERT "%X\n", p[i]);
    }

    printk(KERN_ALERT "Inside the %s function, %s\n", __FUNCTION__, p);
    kfree(p);
    return length;
}

int simple_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

// To hold the file operations performed on this device
struct file_operations simple_file_operation = {
    .owner = THIS_MODULE,
    .open = simple_open,
    .read = simple_read,
    .write = simple_write,
    .release = simple_close
};

//__init, __initdata, will remove thie function in memory, to save some memory

//__initdata int count = 5;

int count = 1;
module_param(count, int, 0644);
/*
Using module_param, you can pass parameter to module ko:
    insmod sim_module.ko count=10

Last arg is permission.

Or modify parameter dynamically:
    $ cat /sys/module/sim_module/parameters/count
    10
    $ echo 5 | sudo tee /sys/module/sim_module/parameters/count
*/

__init int func1(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

int func2(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}
EXPORT_SYMBOL(func2);

__init int simple_module_init(void)
{
    int i = 0;
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    for (i = 0; i < count; i++)
    {
        printk(KERN_ALERT "Hello, index = %d\n", i);
    }
    func1();
    func2();

    // Regester with kernel, indicate that we are registering a char dev driver
    register_chrdev(240/* Major Number */,
                    "Simple Char Drv"/* Name of the driver */,
                    &simple_file_operation/* File Operations */);
    return 0;
}

void simple_module_exit(void)
{
    int i = 0;
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    for (i = 0; i < count; i++)
    {
        printk(KERN_ALERT "Bye, index = %d\n", i);
    }
    func2();

    // Unregster the character device driver
    unregister_chrdev(240, "Simple Char Drv");
}

module_init(simple_module_init);
module_exit(simple_module_exit);

