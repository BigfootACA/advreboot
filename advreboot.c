#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/syscall.h>
#include<linux/reboot.h>
#include<getopt.h>
static int usage(int code){
	fprintf(stderr,"Usage: advreboot <COMMAND>\n");
	exit(code);
	return code;
}
int main(int argc,char**argv){
	static struct option lo[]={
		{"help",no_argument,0,'h'},
		{0,0,0,0}
	};
	int o;
	while((o=getopt_long(argc,argv,"h",lo,NULL))>0)switch(o){
		case 'h':return usage(0);
		case '?':return usage(2);
		default:return 1;
	}
	if(argc<=optind){
		fprintf(stderr,"advreboot: missing command\n");
		return 2;
	}else if(argc>optind+1){
		fprintf(stderr,"advreboot: too many arguments\n");
		return 2;
	}
	sync();
	return (int)syscall(
		SYS_reboot,
		LINUX_REBOOT_MAGIC1,
		LINUX_REBOOT_MAGIC2,
		LINUX_REBOOT_CMD_RESTART2,
		argv[optind]
	);
}
