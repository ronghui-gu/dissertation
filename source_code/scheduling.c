void resched (int otid) {
  int ntid =deQ_t(rdq(cpu));
  tcb[ntid].tds = RUN;
  set_tid (ntid);
  cswitch (&kctxt[otid],
           &kctxt[ntid]);
}
void poll_pending () {
  uint pid =<@$\intp$@>deQ(pendq());
  if (pid != INVALID_TID) {
    tcb[pid].state = READY;
    <@$\intp$@>enQ(rdq(), pid);
  }
}
void yield () {// <@$\kappa_\yield$@>
  int t = get_tid ();
  tcb[t].state = READY;
  <@$\intp$@>poll_pending ();
  enQ_t (rdq(), t);
  resched (t);
}
void sleep (int q){// <@$\kappa_\sleep$@>
  int t = get_tid ();
  tcb[t].tds = SLEEP;
  <@$\intp$@>enQ (slpq(q),t);
  resched (t);
}
