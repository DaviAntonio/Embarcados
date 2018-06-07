#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Davi");
MODULE_DESCRIPTION(descr_str);

/* Variáveis globais usadas como parametros de entrada.
Variável global em módulo está disponível para outros módulos
(veja o arquivo /proc/kallsyms).
Cuidado com o nome da variável
*/

static char *descr_str  = "User, please set string";

// module_param(foo, int, 0000)
//    1o parametro: nome
//    2o parametro: tipo
//    3o parametro: bits de permissao no sistema de arquivos sysfs

module_param(descr_str, charp, 0000);
MODULE_PARM_DESC(descr_str, "String de entrada, modificar");

int hello_init(void)
{
	printk(KERN_INFO "Hello World,  = %s\n", descr_str);
	return 0;
}

void hello_exit(void)
{
	pr_alert("Goodbye World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
