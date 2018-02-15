#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_hello_world 318
#define SYS_sh_task_info 319


int main(int argc, char **argv){
	if(argc < 3){
		return -1;
	}
	long pid = atoi(argv[1]);
	long res = syscall(SYS_sh_task_info,pid,argv[2]);
	printf("Call returned with %ld\n", res);
	if(res==0){
		printf("Reading from File that was passed to syscall\n\n");
		FILE * fp;
		char * line;
		size_t len = 0;
		size_t read;
		fp = fopen(argv[2],"r");
		if(fp==NULL)
			exit(EXIT_FAILURE);

		while((read=getline(&line,&len,fp))!=-1)
		{
			printf("%s", line);
		}
		fclose(fp);
		if(line)
			free(line);
	}
	return 0;
}

// #ifndef TASK_INFO_H
// #define TASK_INFO_H
// struct task_info_res{
// 	long state;
// 	int cpu;
// 	int prio, static_prio, normal_prio;
// 	unsigned int rt_priority;
// 	pid_t pid;
// 	pid_t tgid;
// 	struct thread_struct thread;
// 	struct sched_entity se;

// 	sigset_t blocked;
// 	sigset_t real_blocked;
/* Below fields were deprecated from original patchfile */
// 	int pid,parentPid,gid;
// 	unsigned long userTime,systemTime, numContextSwitches;
// 	unsigned long long totalRunTime;
// 	unsigned int time_slice, policy;
// 	char name[16];
// };
// #endif
// struct task_info_res rt;

// printf("Task id - %d\n", rt.pid);
// printf("Parent Task id - %d\n", rt.parendPid);
// printf("Group id - %d\n", rt.gid);
// printf("CPU Time in user mode - %lu\n", rt.userTime);
// printf("CPU Time in System mode - %lu\n", rt.systemTime);
// printf("Current State - %ld\n", rt.state);
// printf("Scheduled Average Running Time - %llu\n", (rt.totalRunTime));
// printf("Scheduling time slice - %u\n", (rt.time_slice));
// printf("Scheduling Policy - %d\n", rt.policy);
// printf("Number of Context Switches - %lu\n", (rt.numContextSwitches));
// printf("Exece'd File Name - %s\n", rt.name);