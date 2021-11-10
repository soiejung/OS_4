# OS_4
* 리눅스 커널 스케줄링 정책을 확인 할 수 있는 프로그램
* 커널 수정을 통한 Real time FIFO 스케줄러 구현

1. 과제 목표

* 기본 CFS를 확인 할 수 있는 프로그램 구현
* 조정된 NICE 값을 적용한 CFS를 확인 할 수 있는 프로그램 구현
* 커널 수정을 통한 Real time FIFO 스케줄러 구현

2. 기본 지식

* 리눅스 커널의 스케줄링 정책은 기본적으로 CFS를 사용함
* nice()함수를 통해서 프로세스의 NICE값을 조절할 수 있음
* root에서만 음수를 통해서 우선순위 높일 수 있음
* /usr/src/linux/linux-5.11.22/kernel/sched/core.c 에서 커널 소스 수정

3. 구현 내용

* 기본 CFS를 확인 할 수 있는 프로그램
* 조정된 NICE 값을 적용한 CFS를 확인 할 수 있는 프로그램
* 커널 수정을 통한 Real time FIFO 스케줄러

1) sched_fork 함수에 추가
	if(p->policy == SCHED_NORMAL){
		p->prio = current->normal_prio - NICE_WIDTH -
			PRIO_TO_NICE(current->static_prio);
		p->normal_prio = p->prio;
		p->rt_priority = p->prio;
		p->policy = SCHED_FIFO;
		p->static_prio = NICE_TO_PRIO(0);
	}
  
2) _sched_setscheduler 함수에 추가
	if(attr.sched_policy == SCHED_NORMAL){
                attr.sched_priority = param->sched_priority -
                        NICE_WIDTH - attr.sched_nice;
                attr.sched_policy = SCHED_FIFO;
  }
