#include "leetcode.h"

void Solution::reverseBetweenTest() {
  ListNode sen(0), *p=&sen;
  while(cin.getline(BUF, BUFN)) {
    stringstream sin(BUF);
    int i, m, n;
    for(; sin >> i; p=p->next ) {
      p->next = new ListNode(i);
    }
    cin >> m >> n;
    cin.getline(BUF, BUFN);
    cout << reverseBetween(sen.next, m, n ) << endl;
    sen.free(); sen.next = 0; p=&sen;
  }
}

ListNode * Solution::reverseBetween(ListNode *head, int m, int n) {
  ListNode sen(0), *pre, *p, *e, *h, *t, *pn;
  sen.next = head;
  for(e=&sen; e && n; e=e->next, --n);
  if(!e) return head;

  t = e->next;
  for(p=&sen; m; pre=p, p=p->next, --m) ;
  h = pre;
  for(; p!=t; pre=p, p=pn) {
    pn = p->next;
    p->next = pre;
  }
  h->next->next = t;
  h->next = pre;

  return sen.next;
}
