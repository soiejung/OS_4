#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void Mul(int result[][5], int a[][5], int b[][5]){//매트릭스 곱

        int temp;
        for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){

                        temp =0;

                        for(int z=0;z<5;z++){

                                temp += a[i][z]*b[i][z];

                        }
                        result[i][j] = temp;
                }
        }
}

void calculate(int result[][5]){//프로세스가 해야할 일

        int data_1[25], data_2[25], a[5][5], b[5][5];

        for(int i=0; i<25; i++){

                data_1[i] = rand()%100+1;
                data_2[i] = rand()%100+1;
        }
        for(int i=0; i<5; i++){

                for(int j=0; j<5; j++){

                        a[i][j] = data_1[5*i+j];
                        b[i][j] = data_2[5*i+j];
                }
        }
        Mul(result,a,b);
}



int main(){

	int N=21;
	pid_t pid[N];

	int childStatus;


	srand((int)time(NULL));

	int result[5][5];

	for(int i=0; i<21; i++){

		pid[i]=fork();
		if(pid[i]==0){

			for(int i=0;i<10000000;i++){
				calculate(result);
			}
			exit(0);
		}else if(pid[i]>0){
			printf("%d process begins\n",pid[i]);
		}
		

	}


	for(int i=0;i<21;i++){

		pid_t terminatedChild = wait(&childStatus);
		if(WIFEXITED(childStatus)){

			printf("%d process ends\n",terminatedChild);
		}
	}

	printf("---------- All processes end ----------\n");

	return 0;
}


