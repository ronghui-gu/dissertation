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
tcb tcbp[64];
tdq tdqp[256];
tcb * deQ_t(tdq *i){// <@$\kappa_\mathsf{deQ\_t}$@>
  tcb *res = null;
  if (!i) return res;
  tcb *head = i -> head;
  if (!head) return res;
  res = head;
  tcb *next = head -> next;
  if (!next) 
    i->head = i->tail =null;
  else {
    next -> prev = null;
    i -> head = next;
  }
  return res;
}
tcb * deQ(tdq *i){// <@$\kappa_\mathsf{deQ}$@>
  <@$\intp\acq$@>(q_loc(i));
  tcb *res = deQ_t(i);
  <@$\intp\rel$@>(q_loc(i));
  return res;
}
