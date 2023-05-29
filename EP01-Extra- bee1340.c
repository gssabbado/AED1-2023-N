#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define true 1
#define false 0

//*** Estrutura da Fila ***

typedef struct bagQueue{
	int data;
	struct bagQueue *next;
}NodeQueue;

typedef struct Queue {
	NodeQueue *head;
	NodeQueue *tail;
}TQueue;

//*** Estrutura da Pilha ***

typedef struct bagStack {
	int data;
	struct bagStack *next;
}NodeStack;

typedef struct Stack {
	NodeStack *top;
}TStack;

//*** Estrutura da Fila de Prioridade ***

typedef struct bagPQueue {
	int data;
	int priority;
	struct bagPQueue *next;
}NodePQueue;

typedef struct PQueue {
	int size;
	NodePQueue v[MAX];
}TPQueue;

//*** Funções da Fila ***

void startQueue (TQueue *queue) {
	queue->head = NULL;
	queue->tail = NULL;
}

void pushQueue (TQueue *queue, int x) { 
	NodeQueue *aux;
	
	aux = (NodeQueue*) malloc(sizeof(NodeQueue));
	
	/*if (!aux)
		exit(1);
	*/		
	if (queue->head) {
		queue->tail->next = aux;
		aux->next = NULL;
	}	
	else {
		queue->head = aux;
	}	
	
	queue->tail = aux;
	aux->data = x;
}

void popQueue (TQueue *queue) {
	NodeQueue *aux;
	
	if (queue->head) {
		if (queue->head->next) {
			aux = queue->head;
			queue->head = queue->head->next;
			free(aux);
			return;
		}
		else {
			aux = queue->head;
			queue->head = queue->tail = NULL;
			return;
		}
	}
	else {
		return;
	}
	
}

int firstQueue (TQueue *queue) {
	return queue->head->data;
}

//*** Funções da Pilha ***
void startStack (TStack *stack) {
	stack->top = NULL;
}

void pushStack (TStack *stack, int x) {
	NodeStack *aux;
	
	aux = (NodeStack*) malloc(sizeof(NodeStack));
	
	/*if (!aux)
		exit(1);
	*/
	aux->next = stack->top;
	stack->top = aux;
	aux->data = x;
}

void popStack (TStack *stack) {
	NodeStack *aux;
	
	aux = stack->top;
	
	if(aux) {
		stack->top = aux->next;
		free(aux);
	}
}

int top (TStack *stack) {
	return stack->top->data;
}


//*** Funções da Fila de Prioridade ***

TPQueue *startPQueue () {
	TPQueue *aux;
	
	aux = (TPQueue*) malloc(sizeof(TPQueue));
	
	if(aux)
		aux->size = 0;
	
	return aux;
}

void BalanceInsertion (TPQueue *pqueue, int leaf) {
	int root;
	NodePQueue tmp;
	
	root = (leaf - 1) / 2;
	
	while (leaf > 0 && pqueue->v[root].priority <= pqueue->v[leaf].priority) {
		tmp = pqueue->v[leaf];
		pqueue->v[leaf] = pqueue->v[root];
		pqueue->v[root] = tmp;
		
		leaf = root;
		root = (root - 1) / 2;
	}
}


void pushPQueue (TPQueue *pqueue, int priority, int x) {
	/*if (pqueue == NULL) 
		exit(1);
	if (pqueue->size == MAX) 
		exit(1);
	*/	
	pqueue->v[pqueue->size].data = x;
	pqueue->v[pqueue->size].priority = priority;
	BalanceInsertion(pqueue, pqueue->size);
	++pqueue->size;
}


int firstPQueue (TPQueue *pqueue) {
	if (pqueue == NULL || pqueue->size == 0)
		return 0;
	
	return pqueue->v[0].data;
}

void BalanceRemoval (TPQueue *pqueue, int root) {
	int leaf;
	NodePQueue tmp;
	
	leaf = 2 * root + 1;
	
	while (leaf < pqueue->size) {
		if (leaf < pqueue->size - 1)
			if (pqueue->v[leaf].priority < pqueue->v[leaf + 1].priority)
				++leaf;
		
		if (pqueue->v[root].priority >= pqueue->v[leaf].priority)
			break;
		
		tmp = pqueue->v[root];
		pqueue->v[root] = pqueue->v[leaf];
		pqueue->v[leaf] = tmp;
		
		root = leaf;
		leaf = 2 * root + 1;
	}
}


void popPQueue (TPQueue *pqueue) {
	/*if (pqueue == NULL);
		exit(1);
	if (pqueue->size == 0);
		exit(1);
	*/
	--pqueue->size;
	pqueue->v[0] = pqueue->v[pqueue->size];
	BalanceRemoval(pqueue, 0);			
}

//*** ------------------ ***

int main () {
	int n;
	
	while (scanf("%d", &n) != EOF){
		TQueue queue;
		TStack stack;
		TPQueue *pqueue;
		int command, x, i;
		_Bool isQueue, isStack, isPQueue;
	
		isQueue = true;
		isPQueue = true;
		isStack = true;
	
		startQueue(&queue);
		startStack(&stack);
		pqueue = startPQueue();	
	
		for (i = 0; i < n; i++) {	
			scanf("%d %d", &command, &x);
		
			if(command == 1) {
				pushQueue(&queue, x);
				pushStack(&stack, x);
				pushPQueue(pqueue, x, x);
			}
			else {
				if (top(&stack) != x)
					isStack = false;
				else
					popStack(&stack);
			
				if (firstQueue(&queue) != x)
					isQueue = false;
				else
					popQueue(&queue);
			
				if (firstPQueue(pqueue) != x)
					isPQueue = false;
				else
					popPQueue(pqueue);
			}		
		}
//	printf("print\n");
			
		if (!isQueue && !isStack && !isPQueue)
			printf("impossible\n");
		else if (isQueue && isStack)
				printf("not sure\n");
		else if (isQueue && isPQueue)
			printf("not sure\n");		
		else if (isPQueue && isStack)
			printf("not sure\n");	
		else if (isQueue)
			printf("queue\n");	
		else if (isPQueue)
			printf("priority queue\n");		
		else if (isStack)
			printf("stack\n");
	}
	return 0;
}
