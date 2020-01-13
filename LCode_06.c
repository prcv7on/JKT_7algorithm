

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//��̬����data�������±�headָ����ס���β�±�rearָ���β����һ�� ,szΪ����ʵ�����
typedef struct {
	int* data;
	int head, rear, sz;
} MyCircularDeque;


// Checks whether the circular deque is empty or not.
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
	if (obj->head == obj->rear)
		return true;
	return false;
}

// Checks whether the circular deque is full or not.
bool myCircularDequeIsFull(MyCircularDeque* obj) {
	if ((obj->rear + 1) % obj->sz == obj->head)
		return true;
	return false;
}

// Initialize your data structure here. Set the size of the deque to be k. 
MyCircularDeque* myCircularDequeCreate(int k) {
	MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
	if (!obj) return NULL;

	++k;
	obj->data = (int*)malloc(k*sizeof(int));
	obj->head = obj->rear = 0;
	obj->sz = k;
	return obj;
}

// Adds an item at the front of Deque. Return true if the operation is successful.
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
	if (myCircularDequeIsFull(obj))
		return false;

	//headָ����ף���������head��ȡ�������ٲ���
	obj->head = (obj->head - 1 + obj->sz) % obj->sz;
	*(obj->data + obj->head) = value;

	return true;
}

// Adds an item at the rear of Deque. Return true if the operation is successful.
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
	if (myCircularDequeIsFull(obj))
		return false;

	//��Ϊrearָ���β��һλ�������Ȳ��룬������ȡ����
	*(obj->data + obj->rear) = value;
	obj->rear = ++obj->rear % obj->sz;

	return true;
}

//Deletes an item from the front of Deque. Return true if the operation is successful.
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
	if (myCircularDequeIsEmpty(obj))
		return false;

	//����head��ȡ����
	obj->head = ++obj->head % obj->sz;
	return true;
}

// Deletes an item from the rear of Deque. Return true if the operation is successful.
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
	if (myCircularDequeIsEmpty(obj))
		return false;

	//����rear��ȡ������λ����β
	obj->rear = (obj->rear - 1 + obj->sz) % obj->sz;
	return true;
}

// Get the front item from the deque.
int myCircularDequeGetFront(MyCircularDeque* obj) {
	if (myCircularDequeIsEmpty(obj))
		return -1;
	return *(obj->data + obj->head);
}

// Get the last item from the deque.
int myCircularDequeGetRear(MyCircularDeque* obj) {
	if (myCircularDequeIsEmpty(obj))
		return -1;

	return *(obj->data + (obj->rear + obj->sz - 1) % obj->sz);//ע��rear-1��ȡ����
}

void myCircularDequeFree(MyCircularDeque* obj) {
	free(obj->data);
	free(obj);
}

/**
* Your MyCircularDeque struct will be instantiated and called as such:
* MyCircularDeque* obj = myCircularDequeCreate(k);
* bool param_1 = myCircularDequeInsertFront(obj, value);
* bool param_2 = myCircularDequeInsertLast(obj, value);
* bool param_3 = myCircularDequeDeleteFront(obj);
* bool param_4 = myCircularDequeDeleteLast(obj);
* int param_5 = myCircularDequeGetFront(obj);
* int param_6 = myCircularDequeGetRear(obj);
* bool param_7 = myCircularDequeIsEmpty(obj);
* bool param_8 = myCircularDequeIsFull(obj);
* myCircularDequeFree(obj);
*/

int main()
{
	int k = 10;
	bool b[6];
	MyCircularDeque* obj = myCircularDequeCreate(k);
	b[0] = myCircularDequeInsertFront(obj, 12);
	b[1] = myCircularDequeInsertLast(obj, 23);
	myCircularDequeInsertLast(obj, 34);
	myCircularDequeInsertLast(obj, 35);
	b[2] = myCircularDequeDeleteFront(obj);
	b[3] = myCircularDequeDeleteLast(obj);
	int param1 = myCircularDequeGetFront(obj);
	int param2 = myCircularDequeGetRear(obj);
	b[4] = myCircularDequeIsEmpty(obj);
	b[5] = myCircularDequeIsFull(obj);
	myCircularDequeFree(obj);

	for (int i = 0; i < 6; ++i) {
		printf("%d ",b[i]);
	}
	printf("\n");
	printf("param1 = %d \n", param1);
	printf("param2 = %d \n", param2);

	
	system("pause");

}





