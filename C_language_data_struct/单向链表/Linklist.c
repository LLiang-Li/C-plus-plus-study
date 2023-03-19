#include"Linklist.h"
//初始化
LinkList* Init_LinkList() {
	LinkList* List = (LinkList*)malloc(sizeof(LinkList));
	List->size = 0;
	List->head = (Linknode*)malloc(sizeof(Linknode));
	List->head->next = NULL;
	List->head->data = NULL;
	return List;
}
//插入
void Insert_LinkList(LinkList* list, int pos, void* data) {
	if (list == NULL)
		return;
	if (data == NULL)
		return;

	if (pos < 0 || pos > list->size) {
		pos = list->size; 
	}
		Linknode* new_node = (Linknode*)malloc(sizeof(Linknode));
		new_node->data = data;
		new_node->next = NULL;

		Linknode* now_node = list->head;
		for (int i = 0; i < pos; i++)
			now_node = now_node->next;
		new_node->next = now_node->next;
		now_node->next = new_node;
		list->size++;
	
	
}
//删除
void RemoveByPos_LinkList(LinkList* list, int pos) {
	if (list == NULL)
		return;
	if (pos > 0 && pos < list->size) {
		Linknode* now_node = list->head;
		for (int i = 0; i < pos; i++)
			now_node = now_node->next;
		Linknode* delete_node = now_node->next;
		now_node->next = delete_node->next;
		free(delete_node);
	}
	list->size--;

}
//长度
int Size_LinkList(LinkList* list) {
	return list->size;
}
//返回第一个点
void* Front_LinkList(LinkList* list) {
	return list->head->next->data;
}
//销毁
void Free_LinkList(LinkList* list) {
	if (list == NULL)
		return;
	Linknode* now_node = list->head;
	Linknode* free_node;
	while (now_node != NULL)
	{
		free_node = now_node;
		now_node = now_node->next;
		free(free_node);
	}
	free(list);
}
//查找
int Find_LinkList(LinkList* list, void* data) {
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	Linknode* now_node = list->head;
	for (int i = 0; i < list->size; i++) {
		if (data == now_node->data)
			return i;	
		now_node = now_node->next;
	}
	return 0;
}
//显示
void Print_LinkList(LinkList* list, PRINTLINKLIST Print) {
	if (list == NULL)
		return;
	Linknode* now_node = list->head->next;
	for (int i = 0; i < list->size; i++) {
		Print(now_node->data);
		now_node = now_node->next;
	}
	/*while (now_node != NULL)
	{
		Print(now_node->data);
		now_node = now_node->next;
	}*/
}

