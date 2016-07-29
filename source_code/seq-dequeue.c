typedef enum {
  READY,RUN,SLEEP,DEAD
} td_state;
typedef struct tcb {
  td_state tds;
  uint CPU_ID;
  tcb *prev, *next;
} tcb;
typedef struct tdq {
  tcb *head, *tail;
} tdq;
tcb tcbp[64]; // <@$\nu_\textsf{tcbp}$@>
tdq tdqp[256]; // <@$\nu_\textsf{tdqp}$@>
tcb * deQ(tdq *i){// <@$\kappa_\mathsf{deQ}$@>
  tcb *res = null;
  if (!i) return res;
  tcb *head = i -> head;
  if (!head) return res;
  res = head;
  tcb *next = head -> next;
  if (!next) i->head = i->tail =null;
  else {
    next -> prev = null;
    i -> head = next;
  }
  return res;
}
