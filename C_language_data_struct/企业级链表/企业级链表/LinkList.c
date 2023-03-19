#include"LinkList.h"

LinkList* Init_LinkList() {
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}

void Insert_LinkList(LinkList* list, int pos, Node* node) {
	if (list == NULL)
		return;
	if (pos<0 || pos > list->size)
		pos = list->size ;
	Node* now_node = &(list->head);
	for (int i = 0; i < pos; i++)
		now_node = now_node->next;
	node->next = now_node->next;
	now_node->next = node;
	list->size++;
}

void Free_LinkList(LinkList* list) {
	if (list == NULL)
		return;
	free(list);
}

void Remove_LinkList(LinkList* list, int pos) {
	if (list == NULL)
		return;
	if (pos > 0 && pos < list->size) {
		Node* now_node = &(list->head);
			for (int i = 0; i < pos; i++)
				now_node = now_node->next;
		now_node->next = now_node->next->next;
		list->size--;
	}

}

void Print_LinkList(LinkList* list, PRINTNODE prin) {
	if (list == NULL)
		return;
	Node* now_node = (list->head.next);
	for (int i = 0; i < list->size; i++) {
		prin(now_node);
		now_node = now_node->next;
	}
}