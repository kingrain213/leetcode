/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

注意：
1）主要考虑两数相加后进位问题，当前和的进位，要加到下一位上，注意最后一个判断，是否还剩余有进位数字
2）while的时候，两个非空用的是“或||”的关系，不是链表合并，没法直接拷贝赋值
*/
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* newHead = new ListNode(0);
	ListNode* p = l1;
	ListNode* q = l2;
	ListNode* curr = newHead;
	int carry = 0;
	while (p!= NULL or q != NULL)
	{
		int x = (p != NULL) ? p->val : 0;
		int y = (q != NULL) ? q->val : 0;
		int sum = x + y + carry;
		carry = sum / 10;
		curr.next = new ListNode(sum%10);
		curr = curr->next;
		if (p != NULL) p = p->next;
		if (q != NULL) q = q->next;
	}
	if(carry > 0){
		curr->next = new ListNode(carry);
	}
	
	return newHead->next;
}
