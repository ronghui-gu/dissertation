struct fifobbq {
  utin insrtQ, rmvQ; 
  uint n_rmv, n_insrt;
  uint front, next;
  uint T[MAX], loc;
} q;

void remove(){
  uint cv, pos, t;
  <@$\intp$@>acq (q.loc);
  pos = q.n_rmv ++;
  cv = my_cv ();
  <@$\intp$@>enQ (q.rmvQ, cv);
  while(q.front < pos ||
      q.front == q.next)
    <@$\intp$@>wait (cv, q.loc); 

  t = q.T[q.front % MAX]
  q.front ++;
  
  cv=<@$\intp$@>peekQ (q.insrtQ);
  if (cv != NULL)
      <@$\intp$@>signal (cv);
  <@$\intp$@>deQ (q.rmvQ);
  cv = <@$\intp$@>peekQ (q.rmvQ);
  if (cv != NULL)
      <@$\intp$@>signal (cv);
  <@$\intp$@>rel_lock (q.loc);
  return t; 
}
