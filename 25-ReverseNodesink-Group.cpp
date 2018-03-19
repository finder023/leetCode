class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		vector<ListNode*> nodes(k, NULL);
		ListNode* tag = new ListNode(0);
		tag->next = head;
		ListNode* pre = tag;
		ListNode* node = head;
		ListNode* next;
		bool isReversed = false;
		while (node != NULL) {
			//判断是否足够k个节点
			for (int i = 0; i<k; ++i) {
				if (node != NULL) {
					nodes[i] = node;
					node = node->next;
				}
				else {
					isReversed = true;
					break;
				}
			}
			if (isReversed) break;
			next = node;
			//对k个节点进行反转
			node = pre;
			for (int i = k - 1; i >= 0; --i) {
				node->next = nodes[i];
				node = node->next;
			}
			node->next = next;
			pre = node;
			node = pre->next;
		}
		return tag->next;
	}

};
