Inductive tcb :=
| TCBUndef
| TCBV (tds: td_state) (CPU:Z).
Inductive tdq := List Z.
Record abs<@$'$@> := 
{tcbp:ZMap.t tcb; tdqp:ZMap.t tdq}.

// <@$L_{q2}$@> primitive
Function <@$\sigma_\textsf{deQ}$@> a i := 
 match (a.tdqp i) with 
   | head :: q0 => 
     (a0 {tdqp, i: q0}, head)    
   | nil => (a, -1) 
 end.