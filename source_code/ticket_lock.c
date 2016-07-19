// <@$\kappa_\acq$@>
void acq (uint n, uint b) {
  uint myt=<@$\intp$@>FAI_ticket(b);
  while(<@$\intp$@>get_now(b)!=myt){}
  <@$\intp$@>pull(b); 
}
// <@$\kappa_\rel$@>
void rel (uint b) {
  <@$\intp$@>push(b);
  <@$\intp$@>inc_now(b); 
}
