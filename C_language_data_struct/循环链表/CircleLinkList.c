#include"CircleLinkList.h"
//初始化
CircleLinkList* Init_Circle_Link_List() {
	CircleLinkList* list = (CircleLinkList*)malloc(sizeof(CircleLinkList));
	list->size = 0;
	list->head.next = &(list->head);
	return list;
}

//插入
void Insert_Circle_Link_List(CircleLinkList* list, int pos,Node* val) {
	if (list == NULL)
		return;
	if (val == NULL)
		return;
	if (pos<0 || pos > list->size)
		pos = list->size;
	//Node* now_node = list->head.next;
	Node* now_node = &(list->head);
	for (int i = 0; i < pos; i++)
		now_node = now_node->next;
	val->next = now_node->next;
	now_node->next = val;
	list->size++;
}

//删除位置
void Remove_bypos_Circle_Link_List(CircleLinkList* list, int pos) {
	if (list == NULL)
		return;
	if (pos > 0 && pos < list->size) {
		Node* now_node = list->head.next;
		for (int i = 0; i < pos-1; i++)
			now_node = now_node->next;
		now_node->next = now_node->next->next;
		list->size--;
	}

}

//删除值
void Remove_value_Circle_Link_List(CircleLinkList* list, Node* val, COMPARE Compare) {
	if (list == NULL)
		return;
	if (val == NULL)
		return;
	Node* pre_node = &(list->head);
	Node* now_node = pre_node->next;
	for (int i = 0; i < list->size; i++) {
		if (Compare(now_node, val)) {
			pre_node->next = pre_node->next->next;
			list->size--;
			break;
		}
		pre_node = now_node;
		now_node = now_node->next;
	}
}

//返回size
int Size_Circle_Link_List(CircleLinkList* list) {
	return list->size;
}

//返回头节点
Node* Size_Head_Link_List(CircleLinkList* list) {
	return &(list->head);
}

//打印
void Pirnt_Head_Link_List(CircleLinkList* list, MYPRINT Prin) {
	if (list == NULL)
		return;
	Node* now_node = list->head.next;
	for (int i = 0; i < list->size; i++) {
		if (now_node == &(list->head)) {
			now_node = list->head.next;
			printf("------------------------\n");
		}
		Prin(now_node);
		now_node = now_node->next;
	}
}

void free_Head_Link_List(list) {
	if (list == NULL)
		return;
	free(list);
}