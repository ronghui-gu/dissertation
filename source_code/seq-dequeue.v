Inductive td_state := 
| READY | RUN | SLEEP | DEAD.
Inductive tcb :=
| TCBUndef
| TCBV (tds: td_state) (CPU prev next:Z).
Inductive tdq :=
| TDQUndef | TDQV (head tail: Z).
Record abs:= 
{tcbp:ZMap.t tcb; tdqp:ZMap.t tdq}.
// <@$L_{q1}$@> primitive
Function <@$\sigma_\textsf{deQ}'$@> a i := 
 match (a.tdqp i) with 
   |TDQUndef => (a, -1)
   |TDQV head tail =>
   match a.tcbp head with 
     |TCBUndef => (a, -1) 
     |TCBV _ _ next =>
     match a.tcbp next with 
       |TCBUndef => 
        let q0 := (TDQV (-1) (-1)) in
        (a {tdqp,i : q0}, head) 
       |TCBV s0 _ nnext =>
        let q0 := (TDQV next tail) in
        let a0 := a {tdqp, i: q0} in
        let b := (TCBV s0 (-1) nnext) in
        (a0 {tcbp, next: b}, head)    
 end end end.