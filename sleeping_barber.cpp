#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define dbg(x) printf("x: %d\n", x);
int cnt, N;
int cus = 0, bar = 1, mut = 2;
int sem_id;
struct sembuf sbuf;

int readCnt(){
	int cnt;
	FILE *fp;
	fp=fopen("in.txt", "r");
	fscanf(fp, "%d", &cnt);
	fclose(fp);
	return cnt;
}

void writeCnt(int cnt){
	FILE *fp;
	fp=fopen("in.txt", "w");
	fprintf(fp, "%d", cnt);
	fclose(fp);
}

void V(int sid, int sno, struct sembuf *sb){
	sb->sem_num = sno;
	sb->sem_op = 1;
	sb->sem_flg = 0;
	semop(sid, sb, 1);
}

void P(int sid, int sno, struct sembuf *sb){
	sb->sem_num = sno;
	sb->sem_op = -1;
	sb->sem_flg = 0;
	semop(sid, sb, 1);
}

void barber(){
    while(true) {
		P(sem_id, cus, &sbuf);
		P(sem_id, mut, &sbuf);
		cnt = readCnt();
		cnt--;
		writeCnt(cnt);
		printf("Barber is cutting hair. Waiting custoer count: %d.\n", cnt);
		if(cnt == 0) printf("No customer waiting. Barber sleeping.\n");
		V(sem_id, bar, &sbuf);
		V(sem_id, mut, &sbuf);
		sleep(2);
	}
}

void customer(){
	P(sem_id, mut, &sbuf);
	cnt = readCnt();
	if((cnt) < N) {
		cnt++;
		writeCnt(cnt);
		printf("New customer in. Waiting customer count: %d\n", cnt);
		V(sem_id, cus, &sbuf);
		V(sem_id, mut, &sbuf);
		P(sem_id, bar, &sbuf);
	}
	else {
		printf("No seats available.\n");
		V(sem_id, mut, &sbuf);
	}
	sleep(1);
}

void customer_entry(){
    int input;
    while(true) {
        scanf("%d", &input);
        if(input == 1) {
            int pid = fork();
            if(pid == 0) {
				printf("New Customer is here\n");
                customer();
            }
        }
    }
}

void sem_Init(int sid, int sno, int val){
	union semnum {
		int val;
		struct sid_ds *buf;
		unsigned short *array;
  	}a;
  	a.val=val;
  	semctl(sid,sno,SETVAL,a);
}

int main(){
    int pid;
    printf("Number of waiting room chairs : ");
    scanf("%d", &N);
	writeCnt(0);

    sem_id=semget(10, 3, IPC_CREAT|0666);

	sem_Init(sem_id, cus, 0);
	sem_Init(sem_id, bar, 0);
	sem_Init(sem_id, mut, 1);

    pid=fork();
    if(pid==0) {
        barber();
    }
    else{
        customer_entry();
    }
    return 0;
}
