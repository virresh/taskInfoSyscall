# taskInfoSyscall
A Kernel Patch for a new sh_task_info system call to write process related information to a given file

Note- this diff is for linux kernel v 3.13.0
The patch primarily modifies the following files:

kernel/sys.c<br>
arch/x86/syscalls/syscall_64.tbl
