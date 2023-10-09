#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct node{

	int data;
	struct node* next;

}NODE;

NODE* createhead()
{
	NODE* headnode = (NODE*)malloc(sizeof(NODE));

	assert(headnode);

	headnode->next = NULL;

	return headnode;

}

NODE* createNode(int data)
{
	NODE* newnode = (NODE*)malloc(sizeof(NODE));

	assert(newnode);

	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

void plist(NODE* head) {

	NODE* pmove = head->next;
	while (pmove != NULL) {

		printf("%d\t", pmove->data);
		pmove = pmove->next;
	}

	printf("\n");

}

void insertByhead(NODE* head, int data)
{
	NODE* newNode = createNode(data);

	newNode->next = head->next;

	head->next = newNode;

}

void insertBytail(NODE* head, int data)
{
	NODE* newnode = createNode(data);
	NODE* ptail = head;

	while (ptail->next != NULL) {

		ptail = ptail->next;
	}

	ptail->next = newnode;

}

void insertByappion(NODE* head, int posdata,int data)
{
	NODE* preNode = head;
	NODE* posNode = head->next;

	while (posNode != NULL && posNode->data != posdata) {

		preNode = posNode;
		posNode = posNode->next;
	}

	if (posNode == NULL) {

		printf("插入失败，没有找到指定位置");

	}
	else {
		NODE* newnode = createNode(data);
		preNode->next = newnode;
		newnode->next = posNode;
	}

}

void deleteByhead(NODE* head)
{
	if (head->next == NULL) {

		printf("链表为空无法删除");
	}
	else {

		NODE* pdelete = head->next;
		head->next = pdelete->next;
		free(pdelete);
		pdelete = NULL;

	}

}

void deleteBytail(NODE* head)
{
	NODE* pretail = head;
	NODE* postail = head->next;

	if (postail == NULL) {

		printf("链表为空无法删除");
		return;
	}
	while (postail->next != NULL) {

		pretail = postail;
		postail = postail->next;
	}

	free(postail);
	postail = NULL;
	pretail->next = NULL;

}

void deleteByappion(NODE* head, int posdata)
{
	NODE* preNode = head;
	NODE* posNode = head->next;

	while (posNode != NULL && posNode->data != posdata)
	{

		preNode = posNode;
		posNode = posNode->next;

	}

	if (posNode == NULL) {

		printf("删除失败，没有找到指定位置");

	}
	else {

		preNode->next = posNode->next;
		free(posNode);
		posNode = NULL;

	}

}

NODE* serch(NODE* head, int posdata)
{
	NODE* pmove = head->next;
	while (pmove != NULL && pmove->data != posdata)
	{
		pmove = pmove->next;
	}

	return pmove;
}

void deleteAllappion(NODE* head, int posdata)
{
	while (serch(head, posdata)) 
	{
		deleteByappion(head, posdata);
	}

}