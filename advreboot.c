#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/syscall.h>
#include<linux/reboot.h>
static int usage(int code){
	fprintf(stderr,"Usage: advreboot <COMMAND>\n");
	exit(code);
	return code;
}
int main(int argc,char**argv){
	if(argc!=2||argv[1][0]=='-')return usage(1);
	sync();
	return (int)syscall(
		SYS_reboot,
		LINUX_REBOOT_MAGIC1,
		LINUX_REBOOT_MAGIC2,
		LINUX_REBOOT_CMD_RESTART2,
		argv[1]
	);
}
