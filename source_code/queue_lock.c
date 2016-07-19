struct qlock{
  volatile uint busy;
};
// <@$\kappa_{\acq\comm{\_q}}$@>
void acq_q (uint n, uint b){
  if (!<@$\intp$@>CAS_qlock(b,0,1))
    <@$\intp$@> sleep (b);
}
// <@$\kappa_{\rel\comm{\_qlock}}$@>
void rel_q (uint b) {
  uint pid =<@$\intp$@>wakeup (b);
  if (pid == INVALID_TID)
    <@$\intp$@> clear_qlock (b);
}
