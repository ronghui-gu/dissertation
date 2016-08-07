// <@$\kappa_{palloc}$@>
uint palloc (uint nps) { 
  uint i = 0, freei = nps;
  while(freei == nps && i < nps){
    uint u = at_get(i);
    if (!u) freei = i;
    i ++;
  }
  if (freei != nps) 
    at_set (freei, 1);
  return freei; 
}
Definition first_free a n:
{(i,t) | 0 <= i < n /\ a.AT(i) = ATv t 0
    /\ (<@$\forall$@> x, 0 <= x < n
        -> <@$\neg$@> a.AT x = ATV _ 0)}
    + { (<@$\forall$@> x, 0 <= x < n
         -> <@$\neg$@> a.AT x = ATV _ 0)}.
Function <@$\spec_\textsf{palloc}$@> a nps :=
   match first_free a nps with
    | inleft (exist (i, t) _) =>
        (a {AT, i : ATV t 1}, i)
    | _ => (a, nps)
   end.
